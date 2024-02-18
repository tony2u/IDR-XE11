//----------------------------------------------------------------------------
#ifndef InputDlgH
#define InputDlgH
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
//----------------------------------------------------------------------------
class TFInputDlg_11011981 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
    TLabeledEdit *edtName;
    void __fastcall FormShow(TObject *Sender);
	void __fastcall edtNameEnter(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:
public:
	virtual __fastcall TFInputDlg_11011981(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFInputDlg_11011981 *FInputDlg_11011981;
//----------------------------------------------------------------------------
#endif    
