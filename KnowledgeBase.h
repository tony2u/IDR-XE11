//---------------------------------------------------------------------------
#ifndef KnowledgeBaseH
#define KnowledgeBaseH
//---------------------------------------------------------------------------
#include <stdio.h>
//---------------------------------------------------------------------------
//Name and data offset information
typedef struct
{
    DWORD	Offset;
    DWORD	Size;
    int     ModId;    //Modules
    int     NamId;    //Names
} OFFSETSINFO, *POFFSETSINFO;
//Fixup info
typedef struct
{
    BYTE        Type;           //'A' - ADR, 'J' - JMP, 'D' - DAT
    DWORD       Ofs;            //Dump start offset
    TCHAR        *Name;
} FIXUPINFO, *PFIXUPINFO;

/*
ModuleDataTable
---------------
//Composed of ModuleCount view records
WORD 	ID;
PSTR 	ModuleName;
PSTR	Filename;
WORD 	UsesNum;
WORD 	UsesID[UsesNum];	//Module identifier array
PSTR	UsesNames[UsesNum];	//Module Name Array

ConstDataTable
--------------
//Composed of ModuleCount view records
WORD 	ModuleID;
PSTR 	ConstName;
BYTE 	Type; //'C'-ConstDecl, 'P'-PDecl (VMT), 'V'-VarCDecl
PSTR 	TypeDef; //Type
PSTR 	Value; //Value
DWORD	DumpTotal;	//Total dump size (dump+relay+fixed)
DWORD 	DumpSize; //Binary Dump Size (RTTI)
DWORD 	FixupNum; //Dump fixed number
BYTE 	Dump[DumpSize]; //Binary Dump (RTTI)
BYTE 	Relocs[DumpSize];
FIXUPINFO Fixups[FixupNum]; //Fixed array

TypeDataTable
-------------
//Composed of TypeCount view records
DWORD   Size; //Size of Type
WORD 	ModuleID;
PSTR 	TypeName;
BYTE 	Kind; //drArrayDef,...,drVariantDef (see start)
DWORD 	VMCnt; //Number of VMT elements (starting from 0)
PSTR 	Decl; //Declaration
DWORD	DumpTotal;	//Total dump size (dump+relay+fixed)
DWORD 	DumpSize; //Binary Dump Size (RTTI)
DWORD 	FixupNum; //Dump fixed number
BYTE 	Dump[DumpSize]; //Binary Dump (RTTI)
BYTE 	Relocs[DumpSize];
FIXUPINFO Fixups[FixupNum]; //locator
DWORD	FieldsTotal;	//Total size of field data
WORD 	FieldsNum; //Number of fields (class, interface, record)
FIELDINFO Fields[FieldNum]; //field
DWORD	PropsTotal;	//The total size of attribute data
WORD 	PropsNum; //Number of attributes (class, interface)
PROPERTYINFO Props[PropNum]; //attribute
DWORD	MethodsTotal;	//The total size of the method
WORD 	MethodsNum; //Number of methods (class, interface)
METHODINFO Methods[MethodNum]; //method

VarDataTable
------------
//Composed of VarCount view records
WORD 	ModuleID;
PSTR 	VarName;
BYTE 	Type; //'V'-Var;'A'-AbsVar;'S'-SpecVar;'T'-ThreadVar
PSTR 	TypeDef;
PSTR 	AbsName; //Keyword absolute

ResStrDataTable
---------------
//Composed of ResStrCount view records
WORD 	ModuleID;
PSTR 	ResStrName;
PSTR 	TypeDef;
PSTR	Context;

ProcDataTable
-------------
//Contains ProcCount structures:
WORD 	ModuleID;
PSTR 	ProcName;
BYTE 	Embedded; //Contains embedded procs
BYTE 	DumpType; //'C' - code, 'D' - data
BYTE 	MethodKind; //'M'-method,'P'-procedure,'F'-function,'C'-constructor,'D'-destructor
BYTE 	CallKind; //1-'cdecl', 2-'pascal', 3-'stdcall', 4-'safecall'
int 	VProc; //Flag for "overload" (if Delphi version > verD3 and VProc&0x1000 != 0)
PSTR 	TypeDef; //Type of Result for function
DWORD	DumpTotal;	//Total size of dump (dump+relocs+fixups)
DWORD 	DumpSz; //Dump size
DWORD 	FixupNum; //Dump fixups number
BYTE 	Dump[DumpSz]; //Binary dump
BYTE 	Relocs[DumpSize];
FIXUPINFO Fixups[FixupNum]; //Fixups
DWORD	ArgsTotal;	//Total size of arguments
WORD 	ArgsNum; //Arguments number
ARGINFO Args[ArgNum]; //Arguments
DWORD	LocalsTotal;	//Total size of local vars
WORD 	LocalsNum; //Local vars number
LOCALINFO Locals[LocalNum]; //Local vars
*/

#define SCOPE_TMP   32  //Temp struct FIELDINFO, to be deleted
typedef struct FIELDINFO
{
    FIELDINFO():xrefs(0){}
    ~FIELDINFO();
    BYTE 	Scope;      //9-private, 10-protected, 11-public, 12-published
    int 	Offset;     //Offset in class instance
    int 	Case;       //Case for record (in other cases 0xFFFFFFFF)
    AnsiString  Name;       //Field Name
    AnsiString  Type;       //Field Type
    TList	*xrefs;		//Xrefs from code
} FIELDINFO, *PFIELDINFO;

typedef struct
{
    BYTE 	Scope;      //9-private, 10-protected, 11-public, 12-published
    int 	Index;      //Readonly, writeonly depends on the settings of 1 and 2 bits
    int 	DispID;     //???
    AnsiString 	Name;       //Attribute Name
    AnsiString 	TypeDef;    //Attribute type
    AnsiString 	ReadName;   //The process of reading attributes or corresponding fields
    AnsiString 	WriteName;  //The process of writing attributes or corresponding fields
    AnsiString 	StoredName; //The process of verifying attributes or values
} PROPINFO, *PPROPINFO;

typedef struct
{
    BYTE 	Scope;      //9-private, 10-protected, 11-public, 12-published
    BYTE 	MethodKind; //'M'-method, 'P'-procedure, 'F'-function, 'C'-constructor, 'D'-destructor
    AnsiString 	Prototype;  //Prototype full name
} METHODINFO, *PMETHODINFO;

typedef struct
{
    BYTE 	Tag;        //0x21-"val", 0x22-"var"
    bool 	Register;   //If true - argument is in register, else - in stack
    int 	Ndx;        //Register number and offset (XX-number, XXXXXX-offset) (0-EAX, 1-ECX, 2-EDX)
    int		Size;		//Argument Size
    AnsiString 	Name;       //Argument Name
    AnsiString 	TypeDef;    //Argument Type
} ARGINFO, *PARGINFO;

typedef struct
{
    int 	Ofs;        //Offset of local var (from ebp or EP)
    int     Size;       //Size of local var
    AnsiString 	Name;       //Local var Name
    AnsiString 	TypeDef;    //Local var Type
} LOCALINFO, *PLOCALINFO;

typedef struct
{
    TCHAR        type;       //'C'-call; 'J'-jmp; 'D'-data
    DWORD       adr;        //address of procedure
    int         offset;     //offset in procedure
} XrefRec, *PXrefRec;


//Class member fill checkbox
#define INFO_DUMP       1
#define INFO_ARGS       2
#define INFO_LOCALS     4
#define INFO_FIELDS     8
#define INFO_PROPS      16
#define INFO_METHODS    32
#define INFO_ABSNAME    64

class MConstInfo
{
public:
    __fastcall MConstInfo();
    __fastcall ~MConstInfo();
public:
    WORD 	    ModuleID;
    AnsiString 	    ConstName;
    BYTE 	    Type;       //'C'-ConstDecl, 'P'-PDecl (VMT), 'V'-VarCDecl
    AnsiString 	    TypeDef;    //type
    AnsiString 	    Value;      //significance
    DWORD 	    DumpSz;     //Binary dump size
    DWORD 	    FixupNum;   //Dump fixed number
    BYTE 	    *Dump;      //Binary dump
};

//Kind byte value of type information
#define drArrayDef          0x4C    //'L'
#define drClassDef          0x46    //'F'
#define drFileDef           0x4F    //'O'
#define drFloatDef          0x49    //'I'
#define drInterfaceDef      0x54    //'T'
#define drObjVMTDef         0x47    //'G'
#define drProcTypeDef       0x48    //'H'
#define drPtrDef            0x45    //'E'
#define drRangeDef          0x44    //'D'
#define drRecDef            0x4D    //'M'
#define drSetDef            0x4A    //'J'
#define drShortStrDef       0x4B    //'K'
#define drStringDef         0x52    //'R'
#define drTextDef           0x50    //'P'
#define drVariantDef        0x53    //'S'
#define drAliasDef          0x41    //'Z'

class MTypeInfo
{
public:
    __fastcall MTypeInfo();
    __fastcall ~MTypeInfo();
public:
    DWORD       Size;
    WORD        ModuleID;
    AnsiString      TypeName;
    BYTE 	    Kind;       //drArrayDef,...,drVariantDef
    WORD 	    VMCnt;      //VMT elements number (from 0)
    AnsiString 	    Decl;       //Declaration
    DWORD 	    DumpSz;     //Binary dump size
    DWORD 	    FixupNum;   //Binary dump fixup number
    BYTE 	    *Dump;      //Binary dump
    WORD 	    FieldsNum;  //Fields number (class, interface, record)
    BYTE        *Fields;
    WORD 	    PropsNum;   //Properties number (class, interface)
    BYTE        *Props;
    WORD 	    MethodsNum; //Methods number (class, interface)
    BYTE        *Methods;
};
//Var Type field
#define VT_VAR          'V'
#define VT_ABSVAR       'A'
#define VT_SPECVAR      'S'
#define VT_THREADVAR    'T'

class MVarInfo
{
public:
    __fastcall MVarInfo();
    __fastcall ~MVarInfo();
public:
    WORD 	ModuleID;
    AnsiString 	VarName;
    BYTE 	Type; //'V'-Var;'A'-AbsVar;'S'-SpecVar;'T'-ThreadVar
    AnsiString 	TypeDef;
    AnsiString 	AbsName; //Keyword absolute
};

class MResStrInfo
{
public:
    __fastcall MResStrInfo();
    __fastcall ~MResStrInfo();
public:
    WORD        ModuleID;
    AnsiString      ResStrName;
    AnsiString      TypeDef;
    //AnsiString      Context;
};

class MProcInfo
{
public:
    __fastcall MProcInfo();
    __fastcall ~MProcInfo();
public:
    WORD        ModuleID;
    AnsiString      ProcName;
    bool        Embedded;   //true-Contains nested procedures
    TCHAR        DumpType;   //'C' - code, 'D' - data
    TCHAR        MethodKind; //'M'-method,'P'-procedure,'F'-function,'C'-constructor,'D'-destructor
    BYTE 	    CallKind;   //1-'cdecl', 2-'pascal', 3-'stdcall', 4-'safecall'
    int 	    VProc;      //checkbox "overload" (If Delphi version > verD3 and VProc&0x1000 != 0)
    AnsiString      TypeDef;    //type
    DWORD 	    DumpSz;     //Binary dump size
    DWORD 	    FixupNum;   //Dump fixed number
    BYTE 	    *Dump;      //Binary dump (including dump, relay, and fixed components)
    WORD 	    ArgsNum;    //Number of program parameters
    BYTE        *Args;      //parameter list
    //WORD 	    LocalsNum;  //Number of local process variables
    //BYTE      *Locals;    //Local variable list
};
//Knowledge Base Science
#define     KB_NO_SECTION       0
#define     KB_CONST_SECTION    1
#define     KB_TYPE_SECTION     2
#define     KB_VAR_SECTION      4
#define     KB_RESSTR_SECTION   8
#define     KB_PROC_SECTION     16

class MKnowledgeBase
{
public:
    __fastcall  MKnowledgeBase();
    __fastcall ~MKnowledgeBase();

    bool __fastcall Open(LPTSTR filename);
    void __fastcall Close();

    const BYTE* __fastcall GetKBCachePtr(DWORD Offset, DWORD Size);
    WORD __fastcall GetModuleID(LPTSTR ModuleName);
    AnsiString __fastcall GetModuleName(WORD ModuleID);
    void __fastcall GetModuleIdsByProcName(LPTSTR ProcName);
    int __fastcall GetItemSection(WORD* ModuleIDs, LPTSTR ItemName);
    int __fastcall GetConstIdx(WORD* ModuleID, LPTSTR ConstName);
    int __fastcall GetConstIdxs(LPTSTR ConstName, int* ConstIdx);
    int __fastcall GetTypeIdxByModuleIds(WORD* ModuleIDs, LPTSTR TypeName);
    int __fastcall GetTypeIdxsByName(LPTSTR TypeName, int* TypeIdx);
    int __fastcall GetTypeIdxByUID(LPTSTR UID);
    int __fastcall GetVarIdx(WORD* ModuleIDs, LPTSTR VarName);
    int __fastcall GetResStrIdx(int from, LPTSTR ResStrContext);
    int __fastcall GetResStrIdx(WORD ModuleID, LPTSTR ResStrContext);
    int __fastcall GetResStrIdx(WORD* ModuleIDs, LPTSTR ResStrName);
    int __fastcall GetProcIdx(WORD ModuleID, LPTSTR ProcName);
    int __fastcall GetProcIdx(WORD ModuleID, LPTSTR ProcName, BYTE* code);
    int __fastcall GetProcIdx(WORD* ModuleIDs, LPTSTR ProcName, BYTE* code);
    bool __fastcall GetProcIdxs(WORD ModuleID, int* FirstProcIdx, int* LastProcIdx);
    bool __fastcall GetProcIdxs(WORD ModuleID, int* FirstProcIdx, int* LastProcIdx, int* DumpSize);
    MConstInfo* __fastcall GetConstInfo(int AConstIdx, DWORD AFlags, MConstInfo* cInfo);
    MProcInfo* __fastcall GetProcInfo(LPTSTR ProcName, DWORD AFlags, MProcInfo* pInfo, int* procIdx);
    MProcInfo* __fastcall GetProcInfo(int AProcIdx, DWORD AFlags, MProcInfo* pInfo);
    MTypeInfo* __fastcall GetTypeInfo(int ATypeIdx, DWORD AFlags, MTypeInfo* tInfo);
    MVarInfo* __fastcall GetVarInfo(int AVarIdx, DWORD AFlags, MVarInfo* vInfo);
    MResStrInfo* __fastcall GetResStrInfo(int AResStrIdx, DWORD AFlags, MResStrInfo* rsInfo);
    int __fastcall ScanCode(BYTE* code, DWORD* CodeFlags, DWORD CodeSz, MProcInfo* pInfo);
    WORD* __fastcall GetModuleUses(WORD ModuleID);
    int __fastcall GetProcUses(LPTSTR ProcName, WORD* uses);
    WORD* __fastcall GetTypeUses(LPTSTR TypeName);
    WORD* __fastcall GetConstUses(LPTSTR ConstName);
    AnsiString __fastcall GetProcPrototype(int ProcIdx);
    AnsiString __fastcall GetProcPrototype(MProcInfo* pInfo);
    bool __fastcall IsUsedProc(int AIdx);
    void __fastcall SetUsedProc(int AIdx);
    bool __fastcall GetKBProcInfo(AnsiString typeName, MProcInfo* procInfo, int* procIdx);
    bool __fastcall GetKBTypeInfo(AnsiString typeName, MTypeInfo* typeInfo);
    bool __fastcall GetKBPropertyInfo(AnsiString className, AnsiString propName, MTypeInfo* typeInfo);
    AnsiString __fastcall IsPropFunction(AnsiString className, AnsiString procName);
    DWORD       Version;
    int         ModuleCount;
    OFFSETSINFO *ModuleOffsets;
    WORD        *Mods;
    BYTE        *UsedProcs;
    const OFFSETSINFO *ConstOffsets;
    const OFFSETSINFO *TypeOffsets;
    const OFFSETSINFO *VarOffsets;
    const OFFSETSINFO *ResStrOffsets;
    const OFFSETSINFO *ProcOffsets;

private:
    bool        Inited;
    FILE        *Handle;
    bool __fastcall CheckKBFile();

    long        SectionsOffset;
    //Modules
    int         MaxModuleDataSize;
    //Consts
    int         ConstCount;
    int         MaxConstDataSize;
    //Types
    int         TypeCount;
    int         MaxTypeDataSize;
    //Vars
    int         VarCount;
    int         MaxVarDataSize;
    //ResStr
    int         ResStrCount;
    int         MaxResStrDataSize;
    //Procs
    int         MaxProcDataSize;
    int         ProcCount;

    //as temp test (global KB file cache in mem)
    const BYTE  *KBCache;
    long        SizeKBFile;
    AnsiString  NameKBFile;

};
//---------------------------------------------------------------------------
#endif

