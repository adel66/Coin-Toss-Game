#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	wxInitAllImageHandlers();
	MainFrame* mainframe = new MainFrame("TossGame");
	mainframe->SetClientSize(1050, 700);
	mainframe->Center();
	mainframe->Show();

	return true;
}
