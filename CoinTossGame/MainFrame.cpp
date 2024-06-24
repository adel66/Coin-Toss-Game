#include "MainFrame.h"
#include "TossingFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateControls();
	SetMinSize(wxSize(1050, 700));
	SetMaxSize(wxSize(1050, 700));
	SetWindowStyle(GetWindowStyle() & ~wxMAXIMIZE_BOX);
	BindEventsHandler();
}


wxString replaceSingleBackslashes(const wxString& input) {
	wxString result;

	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '\\') {
			result += "\\\\";
		}
		else {
			result += input[i];
		}
	}

	return result;
}


void MainFrame::CreateControls()
{
	TopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1050, 100));
	LeftPanel = new wxPanel(this, wxID_ANY, wxPoint(-1, 100), wxSize(200, 600));
	RightPanel = new wxPanel(this, wxID_ANY, wxPoint(200, 100), wxSize(850, 600));
	wxFont TitleFont(wxFontInfo(wxSize(0, 30)).Bold());
	TitleText = new wxStaticText(TopPanel, wxID_ANY, "OOP Based Coin Toss Game", wxPoint(350, 20), wxSize(600, 80));
	TitleText->SetFont(TitleFont);
	PlayBtn = new wxButton(LeftPanel, wxID_ANY, "PLAY", wxPoint(20, 50), wxSize(160, 75));
	RulesBtn = new wxButton(LeftPanel, wxID_ANY, "Rules", wxPoint(20, 150), wxSize(160, 75));
	AboutBtn = new wxButton(LeftPanel, wxID_ANY, "About", wxPoint(20, 250), wxSize(160, 75));
	SupportBtn = new wxButton(LeftPanel, wxID_ANY, "Support", wxPoint(20, 350), wxSize(160, 75));
	wxFont CRTextFont(wxFontInfo(wxSize(0, 20)).Bold());
	CRText = new wxStaticText(RightPanel, wxID_ANY, "copyright - Garamida abderraoufe adel 2024", wxPoint(200, 500), wxSize(300, 30));
	CRText->SetFont(CRTextFont);
	wxString TossCoinImagePath = replaceSingleBackslashes(wxGetCwd().Append("\\resources\\CoinTossImage.png"));
	wxBitmap coinimage(TossCoinImagePath, wxBITMAP_TYPE_PNG);
	CoinTossImage = new wxStaticBitmap(RightPanel, wxID_ANY, coinimage, wxPoint(130, 0), wxSize(600, 500));




}
void MainFrame::BindEventsHandler()
{
	RulesBtn->Bind(wxEVT_BUTTON, &MainFrame::OnClickRulesBtn, this);
	PlayBtn->Bind(wxEVT_BUTTON, &MainFrame::OnClickPlayBtn, this);
	AboutBtn->Bind(wxEVT_BUTTON, &MainFrame::OnClickAboutBtn, this);
	SupportBtn->Bind(wxEVT_BUTTON, &MainFrame::OnClickSupportBtn, this);
}

void MainFrame::OnClickPlayBtn(const wxCommandEvent& evt)
{
	TossingFrame* tossingframe = new TossingFrame("Game");
	tossingframe->SetClientSize(1000, 500);
	tossingframe->Show();
	tossingframe->Center();


}

void MainFrame::OnClickRulesBtn(const wxCommandEvent& evt)
{
	int answer = wxMessageBox("Welcome to Coin Toss ! \nThe rules are very simple :\n You are starting with a zero balance, and the game will go through multiple rounds, in each round you will toss the coins(10 / 20 / 50)DA simultaneously, if any coin lands Heads then it value will be added to your balance, otherwise(tails lands) nothing changes; You must get exactly 100 DA of balance, if you exceed this amount : YOU LOSE !", "Game Rules");

}

void MainFrame::OnClickAboutBtn(const wxCommandEvent& evt)
{
	int answer = wxMessageBox("This is An OOP based basic Coin tossing game that is builded using cpp , check the README.txt file for more informations", "About");
}

void MainFrame::OnClickSupportBtn(const wxCommandEvent& evt)
{
	int answer = wxMessageBox("If You Have any questions do not hesitate to contact me : \nGmail : garamidamohemed@gmail.com", "Support");
}

