#include <wx/wxprec.h>

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
 void OnExit(wxCloseEvent & e);
 void Form_Resize(wxSizeEvent & e);
 void Mouse_Move(wxMouseEvent & e);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
 //SetProcessDPIAware();
 MyFrame *frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 01")
{
 SetTitle(_("Demo 01 - Okno i zdarzenia"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 570, 360);
 Center();

 Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnExit, this);
 Bind(wxEVT_SIZE, &MyFrame::Form_Resize, this);
 Bind(wxEVT_MOTION, &MyFrame::Mouse_Move, this );
}

void MyFrame::OnExit(wxCloseEvent & e)
{
 if (wxMessageDialog(NULL, "Czy na pewno chcesz zamkn��?", "Pytanie", wxOK | wxCANCEL).ShowModal() == wxID_OK) 
 	Destroy();
}

void MyFrame::Form_Resize(wxSizeEvent & e)
{
 this->SetTitle("Zmieniono rozmiar okna: X=" + wxString::Format("%d", e.GetSize().GetWidth()) + "   Y=" + wxString::Format("%d", e.GetSize().GetHeight()));
}

void MyFrame::Mouse_Move(wxMouseEvent & e)
{
 this->SetTitle("Przesuni�to myszk�: X=" + wxString::Format("%d", e.m_x) + "   Y=" + wxString::Format("%d", e.m_y));
}