//---------------------------------------------------------------------------
#ifndef InfosH
#define InfosH

#include "KnowledgeBase.h"
//---------------------------------------------------------------------------
//lastVar
//vmtAdr
//typeIdx??? - for Type search
//---------------------------------------------------------------------------
//Class Methods Information
typedef struct
{
    bool        abstract;   //call @AbstractError
    TCHAR        kind;       //'M' - method; 'V' - virtual; 'D' - dynamic
    int         id;         //ID (for virtual methods - offset, for dynamics - MsgId)
    DWORD       address;    //Call Address
    AnsiString      name;       //Method Name
} MethodRec, *PMethodRec;

//Information about class fields (look VmtSelfPtr)
#define FIELD_PRIVATE   9
#define FIELD_PROTECTED 10
#define FIELD_PUBLIC    11
#define FIELD_PUBLISHED 12

//---------------------------------------------------------------------------
class InfoResStringInfo
{
public:
	AnsiString		value;
};

typedef InfoResStringInfo *PInfoResStringInfo;

class InfoVmtInfo
{
public:
    TStringList     *interfaces;
    TList           *fields;
    TList           *methods;
public:
	__fastcall InfoVmtInfo();
    __fastcall ~InfoVmtInfo();
    void __fastcall AddInterface(AnsiString Value);
    PFIELDINFO __fastcall AddField(DWORD ProcAdr, int ProcOfs, BYTE Scope, int Offset, int Case, AnsiString Name, AnsiString Type);
    bool __fastcall AddMethod(bool Abstract, TCHAR Kind, int Id, DWORD Address, AnsiString Name);
    void __fastcall RemoveField(int Offset);
};

typedef InfoVmtInfo *PInfoVmtInfo;

//procflags
#define     PF_MAYBEEMBED   0x80000000
#define     PF_EMBED        0x40000000
#define     PF_VIRTUAL      0x20000000
#define     PF_DYNAMIC      0x10000000
#define     PF_EVENT        0x08000000
#define     PF_OUTEAX       0x04000000
#define		PF_KBPROTO		0x02000000	//if prototype for kb was got
#define		PF_BPBASED      0x01000000
#define     PF_ARGSIZEG     0x00800000  //If delta between retN and total arguments size > 0
#define     PF_ARGSIZEL     0x00400000  //If delta between retN and total arguments size < 0
#define     PF_METHOD       0x00200000  //is method of class (other than virtual, dynamic or event)
#define     PF_PUBLISHED    0x00100000  //published

#define     PF_ALLMETHODS   (PF_METHOD | PF_VIRTUAL | PF_DYNAMIC | PF_EVENT)
//first 3 bits - call kind (1, 2, 3, 4)

class InfoProcInfo
{
public:
	DWORD			flags;
    WORD            bpBase;    	//First argument distance from base ebp
    WORD            retBytes;
    int             procSize;
    int             stackSize;
    TList           *args;
    TList           *locals;
public:
	__fastcall InfoProcInfo();
    __fastcall ~InfoProcInfo();
    PARGINFO __fastcall AddArg(PARGINFO aInfo);
    PARGINFO __fastcall AddArg(BYTE Tag, int Ofs, int Size, AnsiString Name, AnsiString TypeDef);
    AnsiString __fastcall AddArgsFromDeclaration(LPTSTR Decl, int from, int callKind);
    PARGINFO __fastcall GetArg(int n);
    void __fastcall DeleteArg(int n);
    void __fastcall DeleteArgs();
    PLOCALINFO __fastcall AddLocal(int Ofs, int Size, AnsiString Name, AnsiString TypeDef);
    PLOCALINFO __fastcall GetLocal(int Ofs);
    PLOCALINFO __fastcall GetLocal(AnsiString Name);
    void __fastcall DeleteLocal(int n);
    void __fastcall DeleteLocals();
    void __fastcall SetLocalType(int Ofs, AnsiString TypeDef);
};

typedef InfoProcInfo *PInfoProcInfo;

#define		OP_COMMENT	0x10
#define		OP_CALL		0x11

typedef struct
{
	BYTE			Op;			//Operation
    union
    {
    	int 		Offset;     //Field offset
        DWORD		Address;    //Proc address for OP_CALL
    } Ofs;
    AnsiString			Name;		//Type name
} PICODE, *PPICODE;

class InfoRec
{
public:
    BYTE                counter;
    BYTE		        kind;
    int                 kbIdx;
    AnsiString              type;       //Return value type for function
    PPICODE			    picode;		//Internal code
    TList               *xrefs;
    PInfoResStringInfo	rsInfo;
    PInfoVmtInfo		vmtInfo;
    PInfoProcInfo	    procInfo;
private:
    AnsiString          name;
public:
    __fastcall InfoRec(int APos, BYTE AKind);
    __fastcall ~InfoRec();
    bool __fastcall HasName();
    AnsiString __fastcall GetName();
    int __fastcall GetNameLength();
    void __fastcall SetName(AnsiString AValue);
    void __fastcall ConcatName(AnsiString AValue);
    bool __fastcall SameName(AnsiString AValue);
    void __fastcall AddXref(TCHAR Type, DWORD Adr, int Offset);
    void __fastcall DeleteXref(DWORD Adr);
    void __fastcall ScanUpItemAndAddRef(int fromPos, DWORD itemAdr, TCHAR refType, DWORD refAdr);
    virtual void __fastcall Save(TStream* outs);
    virtual void __fastcall Load(TStream* ins, LPTSTR buf);
    //virtual void __fastcall Skip(TStream* ins, LPTSTR buf, BYTE asKind);
    AnsiString __fastcall MakePrototype(int adr, bool showKind, bool showTail, bool multiline, bool fullName, bool allArgs);
    AnsiString __fastcall MakeDelphiPrototype(int Adr, PMethodRec recM);
    AnsiString __fastcall MakeMultilinePrototype(int Adr, int* ArgsBytes, AnsiString MethodType);
    AnsiString __fastcall MakeMapName(int Adr);
    bool __fastcall MakeArgsManually();
};

typedef InfoRec *PInfoRec;
//---------------------------------------------------------------------------
#endif
