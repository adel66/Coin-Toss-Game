#include "TossingFrame.h"
#include "MainFrame.h"



TossingFrame::TossingFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	SetMinSize(wxSize(1000, 500));
	SetMaxSize(wxSize(1000, 500));
	SetWindowStyle(GetWindowStyle() & ~wxMAXIMIZE_BOX);
	CreateControls();
	BindEventsHandler();
}

void TossingFrame::CreateControls()
{
	MainPanel = new wxPanel(this);
	TossBtn = new wxButton(MainPanel, wxID_ANY, "Toss", wxPoint(400, 350), wxSize(200, 75));
	wxBitmap coin10image(replaceSingleBackslashes(wxGetCwd().Append("\\resources\\coin10.png")), wxBITMAP_TYPE_PNG);
	wxBitmap coin20image(replaceSingleBackslashes(wxGetCwd().Append("\\resources\\coin20.png")), wxBITMAP_TYPE_PNG);
	wxBitmap coin50image(replaceSingleBackslashes(wxGetCwd().Append("\\resources\\coin50.png")), wxBITMAP_TYPE_PNG);
	coin10 = new wxStaticBitmap(MainPanel, wxID_ANY, coin10image, wxPoint(80, 100), wxDefaultSize);
	coin20 = new wxStaticBitmap(MainPanel, wxID_ANY, coin20image, wxPoint(380, 100), wxDefaultSize);
	coin50 = new wxStaticBitmap(MainPanel, wxID_ANY, coin50image, wxPoint(680, 100), wxDefaultSize);
	BalanceBox = new wxStaticBox(MainPanel, wxID_ANY, "Current Balance:", wxPoint(20, 350), wxSize(200, 75));
	BalanceText = new wxStaticText(MainPanel, wxID_ANY, to_string(TossingFrame::Balance), wxPoint(110, 380), wxSize(40, 40));
	wxFont NoteFont(wxFontInfo(wxSize(0, 13)).Bold());
	NoteText = new wxStaticText(MainPanel, wxID_ANY, "Note : Each time you click 'TOSS', A round will start and all three coins will be tossed simultaneously, and a check if the the coins have landed on the \nhead or tail will be excuted, and the Balance will Be Updated accordingly ; Have FUN !", wxPoint(20, 270));
	NoteText->SetFont(NoteFont);

}

void TossingFrame::BindEventsHandler()
{
	TossBtn->Bind(wxEVT_BUTTON, &TossingFrame::OnClickToss, this);
}


string TossingFrame::evaluateToss(Coin* coin, int& b)
{
	bool toss_result = 0;
	toss_result = coin->toss();
	Coin10* ptr10 = dynamic_cast<Coin10*>(coin);
	Coin20* ptr20 = dynamic_cast<Coin20*>(coin);
	Coin50* ptr50 = dynamic_cast<Coin50*>(coin);
	if (ptr10 != nullptr)
	{
		b += toss_result * coin->getValue();

		if (toss_result) {
			return "coin10";
		}
		else {
			return "notcoin10";
		}
	}
	else if (ptr20 != nullptr)
	{
		b += toss_result * coin->getValue();

		if (toss_result) {
			return "coin20";
		}
		else {
			return "notcoin20";
		}
	}
	else if (ptr50 != nullptr)
	{
		b += toss_result * coin->getValue();

		if (toss_result) {
			return "coin50";
		}
		else {
			return "notcoin50";
		}
	}


	return "unknown";
}




void TossingFrame::OnClickToss(const wxCommandEvent& evt)
{
	vector<Coin*> coins;
	static int j = 0;
	srand(static_cast<unsigned int>(std::time(0)));

	if (TossingFrame::Balance < 100)
	{
		coins.push_back(new Coin10);
		coins.push_back(new Coin20);
		coins.push_back(new Coin50);
		string firstoss = evaluateToss(coins.at(j), TossingFrame::Balance);
		j++;
		string secondtoss = evaluateToss(coins.at(j), TossingFrame::Balance);
		j++;
		string thirdtoss = evaluateToss(coins.at(j), TossingFrame::Balance);
		
		j = 0;

		BalanceText->SetLabel(to_string(TossingFrame::Balance));

		if (firstoss == "coin10") {
			firstoss = "Coin 10 landed  : Head";
		}
		else if (firstoss == "coin20") {
			firstoss = "Coin 20 landed  : Head";
		}
		else if (firstoss == "coing 50") {
			firstoss = "Coin 50 landed  : Head";
		}
		else if (firstoss == "notcoin10") {
			firstoss = "Coin 10 landed  : Tail";
		}
		else if (firstoss == "notcoin20") {
			firstoss = "Coin 20 landed  : Tail";
		}
		else if (firstoss == "notcoin50") {
			firstoss = "Coin 50 landed  : Tail";
		}

		if (secondtoss == "coin10") {
			secondtoss = "Coin 10 landed  : Head";
		}
		else if (secondtoss == "coin20") {
			secondtoss = "Coin 20 landed  : Head";
		}
		else if (secondtoss == "coing 50") {
			secondtoss = "Coin 50 landed  : Head";
		}
		else if (secondtoss == "notcoin10") {
			secondtoss = "Coin 10 landed  : Tail";
		}
		else if (secondtoss == "notcoin20") {
			secondtoss = "Coin 20 landed  : Tail";
		}
		else if (secondtoss == "notcoin50") {
			secondtoss = "Coin 50 landed  : Tail";
		}


		if (thirdtoss == "coin10") {
			thirdtoss = "Coin 10 landed  : Head";
		}
		else if (thirdtoss == "coin20") {
			thirdtoss = "Coin 20 landed  : Head";
		}
		else if (thirdtoss == "coin50") {
			thirdtoss = "Coin 50 landed  : Head";
		}
		else if (thirdtoss == "notcoin10") {
			thirdtoss = "Coin 10 landed  : Tail";
		}
		else if (thirdtoss == "notcoin20") {
			thirdtoss = "Coin 20 landed  : Tail";
		}
		else if (thirdtoss == "notcoin50") {
			thirdtoss = "Coin 50 landed  : Tail";
		}

		int result = wxMessageBox(firstoss + "\n" + secondtoss + "\n" + thirdtoss, "Result");

	}

	if (Balance == 100)
	{
		Balance = 0;
		BalanceText->SetLabel(to_string(Balance));
		for (Coin* coinptr : coins)
		{

			delete coinptr;
		}

		int result = wxMessageBox("You WON !", "Congratulations");
	}
	else if (Balance > 100) {
		Balance = 0;
		BalanceText->SetLabel(to_string(Balance));
		j = 0;
		int result = wxMessageBox("You Lost :(", "Result");
		for (Coin* coinptr : coins)
		{

			delete coinptr;
		}
	}


}


