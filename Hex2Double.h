//----------------------------------------------------------------------------
#ifndef Hex2DoubleH
#define Hex2DoubleH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "Misc.h"
//----------------------------------------------------------------------------
class TFHex2DoubleDlg_11011981 : public TForm
{
__published:
    TRadioGroup *rgDataViewStyle;
    TLabeledEdit *edtValue;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall edtValueEnter(TObject *Sender);
    void __fastcall rgDataViewStyleClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:
    int     PrevIdx;
    BYTE    BinData[16];
    void __fastcall Str2Binary(AnsiString AStr);
    AnsiString __fastcall Binary2Str(int BytesNum);
public:
	virtual __fastcall TFHex2DoubleDlg_11011981(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFHex2DoubleDlg_11011981 *FHex2DoubleDlg_11011981;
//----------------------------------------------------------------------------
#endif    
