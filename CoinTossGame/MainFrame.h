#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void CreateControls();
	void BindEventsHandler();
	void OnClickPlayBtn(const wxCommandEvent& evt);
	void OnClickRulesBtn(const wxCommandEvent& evt);
	void OnClickAboutBtn(const wxCommandEvent& evt);
	void OnClickSupportBtn(const wxCommandEvent& evt);


	wxPanel* TopPanel;
	wxPanel* RightPanel;
	wxPanel* LeftPanel;
	wxButton* PlayBtn;
	wxButton* RulesBtn;
	wxButton* AboutBtn;
	wxButton* SupportBtn;
	wxStaticText* TitleText;
	wxStaticText* CRText;
	wxStaticBitmap* CoinTossImage;
	
};


wxString replaceSingleBackslashes(const wxString& input);
