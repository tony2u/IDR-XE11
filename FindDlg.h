//----------------------------------------------------------------------------
#ifndef FindDlgH
#define FindDlgH
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
class TFindDlg_11011981 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
    TComboBox *cbText;
    TLabel *Label1;
    void __fastcall FormShow(TObject *Sender);
	void __fastcall cbTextEnter(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:
public:
	virtual __fastcall TFindDlg_11011981(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TFindDlg_11011981 *FindDlg_11011981;
//----------------------------------------------------------------------------
#endif    
