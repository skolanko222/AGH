#include <wx/wxprec.h>
#include "MyFrame.h"
#include "NieModalnyDlg.h"
//--------------------------------------------------------------------------------------------------------------------------

ModalnyDlg::ModalnyDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
 SetTitle(_("Modalny"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 368, 185);
 Center();

 WxButton1 = new wxButton(this, wxID_ANY, _("OK"), wxPoint(126, 80), wxSize(86, 28), 0, wxDefaultValidator, _("WxButton1"));
 WxButton1->Bind(wxEVT_BUTTON, &ModalnyDlg::WxButton1Click, this);
 WxStaticText1 = new wxStaticText(this, wxID_ANY, _("Wci�nij OK"), wxPoint(44, 24), wxDefaultSize, 0, _("WxStaticText1"));

 Bind(wxEVT_CLOSE_WINDOW, &ModalnyDlg::OnClose, this);
}

void ModalnyDlg::WxButton1Click(wxCommandEvent& event)
{
 EndModal(wxID_OK);
}

//--------------------------------------------------------------------------------------------------------------------------

MyFrame *frame;

NieModalnyDlg::NieModalnyDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
 SetTitle(_("NieModalny"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 378, 210);
 Center();

 WxButton1 = new wxButton(this, wxID_ANY, _("Zako�cz"), wxPoint(150, 115), wxSize(87, 29), 0, wxDefaultValidator, _("WxButton1"));
 WxButton1->Bind(wxEVT_BUTTON, &NieModalnyDlg::WxButton1Click, this);

 WxScrollBar1 = new wxScrollBar(this, wxID_ANY, wxPoint(10, 17), wxSize(334, 19), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
 WxScrollBar1->SetScrollbar(0, 10, 100, 10);
 WxScrollBar1->Bind(wxEVT_SCROLL_THUMBTRACK, &NieModalnyDlg::WxScrollBar1Scroll, this);

 Bind(wxEVT_CLOSE_WINDOW, &NieModalnyDlg::OnClose, this);
}

void NieModalnyDlg::WxScrollBar1Scroll(wxScrollEvent &e)
{
 frame->WxStaticText1->SetLabel(wxString::Format("%d", WxScrollBar1->GetThumbPosition()));
}

//--------------------------------------------------------------------------------------------------------------------------

class MyApp : public wxApp
{
 public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
 //SetProcessDPIAware();
 frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 04")
{
 SetTitle(_("Demo 04 - Hierarchia okien"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 481, 194);
 Center();
 
 WxButton1 = new wxButton(this, wxID_ANY, _("Modalny"), wxPoint(9, 12), wxSize(196, 81), 0, wxDefaultValidator, _("WxButton1"));
 WxButton1->Bind(wxEVT_BUTTON, &MyFrame::WxButton1_Click, this);
 WxButton2 = new wxButton(this, wxID_ANY, _("Niemodalny"), wxPoint(235, 12), wxSize(207, 83), 0, wxDefaultValidator, _("WxButton2"));
 WxButton2->Bind(wxEVT_BUTTON, &MyFrame::WxButton2_Click, this);
 WxStaticText1 = new wxStaticText(this, wxID_ANY, _("WxStaticText1"), wxPoint(10, 110), wxDefaultSize, 0, _("WxStaticText1"));
}

void MyFrame::WxButton1_Click(wxCommandEvent &e)
{
 dialog_modalny = new ModalnyDlg(this);
 dialog_modalny->ShowModal();
}

void MyFrame::WxButton2_Click(wxCommandEvent &e)
{
 dialog_nie_modalny = new NieModalnyDlg(this);
 dialog_nie_modalny->Show(true);
}