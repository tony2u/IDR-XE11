//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Main.cpp", FMain_11011981);
USEFORM("Plugins.cpp", FPlugins);
USEFORM("KBViewer.cpp", FKBViewer_11011981);
USEFORM("Legend.cpp", FLegend_11011981);
USEFORM("ProgressBar.cpp", FProgressBar);
USEFORM("TypeInfos.cpp", FTypeInfo_11011981);
USEFORM("UfrmFormTree.cpp", IdrDfmFormTree_11011981);
USEFORM("StringInfo.cpp", FStringInfo_11011981);
USEFORM("InputDlg.cpp", FInputDlg_11011981);
USEFORM("EditFieldsDlg.cpp", FEditFieldsDlg_11011981);
USEFORM("EditFunctionDlg.cpp", FEditFunctionDlg_11011981);
USEFORM("AboutDlg.cpp", FAboutDlg_11011981);
USEFORM("ActiveProcesses.cpp", FActiveProcesses);
USEFORM("Explorer.cpp", FExplorer_11011981);
USEFORM("IdcSplitSize.cpp", FIdcSplitSize);
USEFORM("FindDlg.cpp", FindDlg_11011981);
USEFORM("Hex2Double.cpp", FHex2DoubleDlg_11011981);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->HelpFile = "";
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFMain_11011981), &FMain_11011981);
		Application->CreateForm(__classid(TFAboutDlg_11011981), &FAboutDlg_11011981);
		Application->CreateForm(__classid(TFActiveProcesses), &FActiveProcesses);
		Application->CreateForm(__classid(TFindDlg_11011981), &FindDlg_11011981);
		Application->CreateForm(__classid(TFHex2DoubleDlg_11011981), &FHex2DoubleDlg_11011981);
		Application->CreateForm(__classid(TFInputDlg_11011981), &FInputDlg_11011981);
		Application->CreateForm(__classid(TFLegend_11011981), &FLegend_11011981);
		Application->CreateForm(__classid(TFProgressBar), &FProgressBar);
		Application->CreateForm(__classid(TFStringInfo_11011981), &FStringInfo_11011981);
		Application->CreateForm(__classid(TFEditFieldsDlg_11011981), &FEditFieldsDlg_11011981);
		Application->CreateForm(__classid(TFEditFunctionDlg_11011981), &FEditFunctionDlg_11011981);
		Application->CreateForm(__classid(TFExplorer_11011981), &FExplorer_11011981);
		Application->CreateForm(__classid(TFIdcSplitSize), &FIdcSplitSize);
		Application->CreateForm(__classid(TFKBViewer_11011981), &FKBViewer_11011981);
		Application->CreateForm(__classid(TFPlugins), &FPlugins);
		Application->CreateForm(__classid(TFTypeInfo_11011981), &FTypeInfo_11011981);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
