#include <wx/wxprec.h>
#include "gui.hpp"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	
	gui* fr = new gui();
	fr->Show(true);
	return true;
}
