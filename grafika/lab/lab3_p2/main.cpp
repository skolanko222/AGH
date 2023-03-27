
#include "wx/wx.h"
#include "MyProject1MyFrame5.h"


class MyApp : public wxApp
{
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
  MyFrame();

private:
  void OnExit(wxCommandEvent &command_event);
};

bool MyApp::OnInit()
{
  wxFrame *mainFrame = new MyProject1MyFrame5(NULL);
  mainFrame->Show(true);
  SetTopWindow(mainFrame);
  return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Monkey Lab_03")
{
  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
void MyFrame::OnExit(wxCommandEvent &event)
{
  Close(true);
}


wxIMPLEMENT_APP(MyApp);

