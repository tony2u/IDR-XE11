//----------------------------------------------------------------------------
#ifndef IdcSplitSizeH
#define IdcSplitSizeH
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
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TFIdcSplitSize : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
    TTrackBar *tbSplitSize;
    void __fastcall OKBtnClick(TObject *Sender);
    void __fastcall CancelBtnClick(TObject *Sender);
    void __fastcall tbSplitSizeChange(TObject *Sender);
private:
public:
	virtual __fastcall TFIdcSplitSize(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFIdcSplitSize *FIdcSplitSize;
//----------------------------------------------------------------------------
#endif    
