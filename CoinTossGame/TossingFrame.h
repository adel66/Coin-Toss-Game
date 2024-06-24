#pragma once
#include <wx/wx.h>
#include <string>
#include "Coin.h"
#include "Coin10.h"
#include "Coin20.h"
#include "Coin50.h"
#include <vector>

using namespace std;

class TossingFrame : public wxFrame
{


public:
	int Balance;
	string evaluateToss(Coin* coin, int& b);
	TossingFrame(const wxString& title);
	void CreateControls();
	void BindEventsHandler();
	void OnClickToss(const wxCommandEvent &evt);

	wxPanel* MainPanel;
	wxStaticBitmap* coin10;
	wxStaticBitmap* coin20;
	wxStaticBitmap* coin50;
	wxButton* TossBtn;
	wxStaticText* BalanceText;
	wxStaticBox* BalanceBox;
	wxStaticText* NoteText;
};

