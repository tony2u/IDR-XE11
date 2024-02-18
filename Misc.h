//---------------------------------------------------------------------------
#ifndef MiscH
#define MiscH
//---------------------------------------------------------------------------
#include "Decompiler.h"
//---------------------------------------------------------------------------
//Float Type
#define     FT_SINGLE       1
#define     FT_DOUBLE       2
#define     FT_EXTENDED     3
#define     FT_REAL         4
#define     FT_COMP         5
#define     FT_CURRENCY     6
//---------------------------------------------------------------------------
//global API
void __fastcall ScaleForm(TForm* AForm);
int __fastcall Adr2Pos(DWORD adr);
AnsiString __fastcall Val2Str0(DWORD Val);
AnsiString __fastcall Val2Str1(DWORD Val);
AnsiString __fastcall Val2Str2(DWORD Val);
AnsiString __fastcall Val2Str4(DWORD Val);
AnsiString __fastcall Val2Str5(DWORD Val);
AnsiString __fastcall Val2Str8(DWORD Val);
DWORD __fastcall Pos2Adr(int Pos);
PInfoRec __fastcall AddToBSSInfos(DWORD Adr, AnsiString AName, AnsiString ATypeName);
void __fastcall AddClassAdr(DWORD Adr, const AnsiString& AName);
void __fastcall AddFieldXref(PFIELDINFO fInfo, DWORD ProcAdr, int ProcOfs, TCHAR type);
void __fastcall AddPicode(int Pos, BYTE Op, AnsiString Name, int Ofs);
int __fastcall ArgsCmpFunction(void *item1, void *item2);
int __fastcall BranchGetPrevInstructionType(DWORD fromAdr, DWORD* jmpAdr, PLoopInfo loopInfo);
bool __fastcall CanReplace(const AnsiString& fromName, const AnsiString& toName);
void __fastcall ClearFlag(DWORD flag, int pos);
void __fastcall ClearFlags(DWORD flag, int pos, int num);
void __fastcall Copy2Clipboard(TStrings* items, int leftMargin, bool asmCode);
int __fastcall ExportsCmpFunction(void *item1, void *item2);
AnsiString __fastcall ExtractClassName(const AnsiString& AName);
AnsiString __fastcall ExtractProcName(const AnsiString& AName);
AnsiString __fastcall ExtractName(const AnsiString& AName);
AnsiString __fastcall ExtractType(const AnsiString& AName);
void __fastcall FillArgInfo(int k, BYTE callkind, PARGINFO argInfo, BYTE** p, int* s);
DWORD __fastcall FindClassAdrByName(const AnsiString& AName);
int __fastcall FloatNameToFloatType(AnsiString AName);
AnsiString __fastcall GetArrayElementType(AnsiString arrType);
int __fastcall GetArrayElementTypeSize(AnsiString arrType);
bool __fastcall GetArrayIndexes(AnsiString arrType, int ADim, int* LowIdx, int* HighIdx);
int __fastcall GetArraySize(AnsiString arrType);
DWORD __fastcall GetChildAdr(DWORD Adr);
DWORD __fastcall GetClassAdr(const AnsiString& AName);
int __fastcall GetClassSize(DWORD adr);
AnsiString __fastcall GetClsName(DWORD adr);
AnsiString __fastcall GetDefaultProcName(DWORD adr);
AnsiString __fastcall GetDynaInfo(DWORD adr, WORD id, DWORD* dynAdr);
AnsiString __fastcall GetDynArrayTypeName(DWORD adr);
AnsiString __fastcall GetEnumerationString(AnsiString TypeName, Variant Val);
AnsiString __fastcall GetImmString(int Val);
AnsiString __fastcall GetImmString(AnsiString TypeName, int Val);
PInfoRec __fastcall GetInfoRec(DWORD adr);
int __fastcall GetLastLocPos(int fromAdr);
AnsiString __fastcall GetModuleVersion(const AnsiString& module);
int __fastcall GetNearestArgA(int fromPos);
int __fastcall GetNearestDownInstruction(int fromPos);
int __fastcall GetNearestDownInstruction(int fromPos, LPTSTR Instruction);
int __fastcall GetNearestUpPrefixFs(int fromPos);
int __fastcall GetNearestUpInstruction(int fromPos);
int __fastcall GetNthUpInstruction(int fromPos, int N);
int __fastcall GetNearestUpInstruction(int fromPos, int toPos);
int __fastcall GetNearestUpInstruction(int fromPos, int toPos, int no);
int __fastcall GetNearestUpInstruction1(int fromPos, int toPos, LPTSTR Instruction);
int __fastcall GetNearestUpInstruction2(int fromPos, int toPos, LPTSTR Instruction1, LPTSTR Instruction2);
DWORD __fastcall GetParentAdr(DWORD Adr);
AnsiString __fastcall GetParentName(DWORD adr);
AnsiString __fastcall GetParentName(const AnsiString& ClassName);
int __fastcall GetParentSize(DWORD Adr);
int __fastcall GetProcRetBytes(MProcInfo* pInfo);
int __fastcall GetProcSize(DWORD fromAdr);
int __fastcall StrGetRecordSize(AnsiString str);
int __fastcall StrGetRecordFieldOffset(AnsiString str);
AnsiString __fastcall StrGetRecordFieldName(AnsiString str);
AnsiString __fastcall StrGetRecordFieldType(AnsiString str);
int __fastcall GetRecordSize(AnsiString AName);
AnsiString __fastcall GetRecordFields(int AOfs, AnsiString AType);
AnsiString __fastcall GetAsmRegisterName(int Idx);
AnsiString __fastcall GetDecompilerRegisterName(int Idx);
AnsiString __fastcall GetSetString(AnsiString TypeName, BYTE* ValAdr);
DWORD __fastcall GetStopAt(DWORD vmtAdr);
DWORD __fastcall GetOwnTypeAdr(AnsiString AName);
PTypeRec __fastcall GetOwnTypeByName(AnsiString AName);
AnsiString __fastcall GetTypeDeref(AnsiString ATypeName);
BYTE __fastcall GetTypeKind(AnsiString AName, int* size);
int __fastcall GetRTTIRecordSize(DWORD adr);
int __fastcall GetPackedTypeSize(AnsiString AName);
AnsiString __fastcall GetTypeName(DWORD TypeAdr);
int __fastcall GetTypeSize(AnsiString AName);
int __fastcall ImportsCmpFunction(void *item1, void *item2);
bool __fastcall IsADC(int Idx);
int __fastcall IsBoundErr(DWORD fromAdr);
bool __fastcall IsConnected(DWORD fromAdr, DWORD toAdr);
bool __fastcall IsBplByExport(const LPTSTR bpl);
bool __fastcall IsDefaultName(AnsiString AName);
DWORD __fastcall IsGeneralCase(DWORD fromAdr, int retAdr);
bool __fastcall IsExit(DWORD fromAdr);
bool __fastcall IsInheritsByAdr(const DWORD Adr1, const DWORD Adr2);
bool __fastcall IsInheritsByClassName(const AnsiString& Name1, const AnsiString& Name2);
bool __fastcall IsInheritsByProcName(const AnsiString& Name1, const AnsiString& Name2);
int __fastcall IsInitStackViaLoop(DWORD fromAdr, DWORD toAdr);
bool __fastcall IsSameRegister(int Idx1, int Idx2);
int __fastcall IsCopyDynArrayToStack(DWORD fromAdr);
bool __fastcall IsValidCodeAdr(DWORD Adr);
bool __fastcall IsValidCString(int pos);
bool __fastcall IsValidImageAdr(DWORD Adr);
bool __fastcall IsValidModuleName(int len, int pos);
bool __fastcall IsValidName(int len, int pos);
bool __fastcall IsValidString(int len, int pos);
bool __fastcall IsXorMayBeSkipped(DWORD fromAdr);
void __fastcall MakeGvar(PInfoRec recN, DWORD adr, DWORD xrefAdr);
AnsiString __fastcall MakeGvarName(DWORD adr);
int __fastcall MethodsCmpFunction(void *item1, void *item2);
void __fastcall OutputDecompilerHeader(FILE* f);
bool __fastcall IsFlagSet(DWORD flag, int pos);
void __fastcall SetFlag(DWORD flag, int pos);
void __fastcall SetFlags(DWORD flag, int pos, int num);
int __fastcall SortUnitsByAdr(void *item1, void* item2);
int __fastcall SortUnitsByNam(void *item1, void* item2);
int __fastcall SortUnitsByOrd(void *item1, void* item2);
AnsiString __fastcall TransformString(LPTSTR str, int len);
AnsiString __fastcall TransformUString(WORD codePage, wchar_t* data, int len);
LPTSTR __fastcall TransformPChar(WORD codePage, LPWSTR data, int len);
LPWSTR __fastcall TransformPWideChar(WORD codePage, LPTSTR data, int len);
AnsiString __fastcall TrimTypeName(const AnsiString& TypeName);
AnsiString __fastcall TypeKind2Name(BYTE kind);
AnsiString __fastcall UnmangleName(AnsiString Name);
//Decompiler
int __fastcall IsAbs(DWORD fromAdr);
int _fastcall IsIntOver(DWORD fromAdr);
int __fastcall IsInlineLengthCmp(DWORD fromAdr);
int __fastcall IsInlineLengthTest(DWORD fromAdr);
int __fastcall IsInlineDiv(DWORD fromAdr, int* div);
int __fastcall IsInlineMod(DWORD fromAdr, int* mod);
int __fastcall ProcessInt64Equality(DWORD fromAdr, DWORD* maxAdr);
int __fastcall ProcessInt64NotEquality(DWORD fromAdr, DWORD* maxAdr);
int __fastcall ProcessInt64Comparison(DWORD fromAdr, DWORD* maxAdr);
int __fastcall ProcessInt64ComparisonViaStack1(DWORD fromAdr, DWORD* maxAdr);
int __fastcall ProcessInt64ComparisonViaStack2(DWORD fromAdr, DWORD* maxAdr);
int __fastcall IsInt64Equality(DWORD fromAdr, int* skip1, int* skip2, bool *immVal, __int64* Val);
int __fastcall IsInt64NotEquality(DWORD fromAdr, int* skip1, int* skip2, bool *immVal, __int64* Val);
int __fastcall IsInt64Comparison(DWORD fromAdr, int* skip1, int* skip2, bool *immVal, __int64* Val);
int __fastcall IsInt64ComparisonViaStack1(DWORD fromAdr, int* skip1, DWORD* simEnd);
int __fastcall IsInt64ComparisonViaStack2(DWORD fromAdr, int* skip1, int* skip2, DWORD* simEnd);
int __fastcall IsInt64Shr(DWORD fromAdr);
int __fastcall IsInt64Shl(DWORD fromAdr);
AnsiString __fastcall InputDialogExec(AnsiString caption, AnsiString labelText, AnsiString text);
AnsiString __fastcall ManualInput(DWORD procAdr, DWORD curAdr, AnsiString caption, AnsiString labelText);
bool __fastcall MatchCode(BYTE* code, MProcInfo* pInfo);
void __fastcall SaveCanvas(TCanvas* ACanvas);
void __fastcall RestoreCanvas(TCanvas* ACanvas);
void __fastcall DrawOneItem(AnsiString AItem, TCanvas* ACanvas, TRect &ARect, TColor AColor, int flags);
int __fastcall IsTryBegin(DWORD fromAdr, DWORD* endAdr);
int __fastcall IsTryBegin0(DWORD fromAdr, DWORD* endAdr);
int __fastcall IsTryEndPush(DWORD fromAdr, DWORD* endAdr);
int __fastcall IsTryEndJump(DWORD fromAdr, DWORD* endAdr);

PFIELDINFO __fastcall GetClassField(AnsiString TypeName, int Offset);
int __fastcall GetRecordField(AnsiString ARecType, int AOfs, AnsiString& name, AnsiString& type);
int __fastcall GetField(AnsiString TypeName, int Offset, AnsiString& name, AnsiString& type);
//---------------------------------------------------------------------------
#endif
