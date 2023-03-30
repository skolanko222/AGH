#include <wx/wxprec.h>
#include "gui.hpp"

class MyApp : public wxApp
{
public:

	gui* mainGui; 
	virtual bool OnInit();
};



bool MyApp::OnInit()
{
	mainGui = new gui();
	mainGui->Show(true);
	return true;
}
wxIMPLEMENT_APP(MyApp);