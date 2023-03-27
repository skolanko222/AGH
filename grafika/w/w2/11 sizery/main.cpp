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
 wxTextCtrl *WxMemo1;
 wxButton *WxButton3;
 wxTextCtrl *WxEdit1;
 wxBoxSizer *WxBoxSizer2;
 wxButton *WxButton2;
 wxButton *WxButton1;
 wxBoxSizer *WxBoxSizer1;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
 //SetProcessDPIAware();
 MyFrame *frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 11")
{
 SetTitle(_("Demo 11 - U�ycie sizers'�w"));
 SetIcon(wxNullIcon);

 WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
 this->SetSizer(WxBoxSizer1);
 this->SetAutoLayout(true);

 WxButton1 = new wxButton(this, wxID_ANY, _("WxButton1"), wxPoint(5, 82), wxSize(86, 32), 0, wxDefaultValidator, _("WxButton1"));
 WxBoxSizer1->Add(WxButton1, 1, wxEXPAND | wxALL, 5);

 WxButton2 = new wxButton(this, wxID_ANY, _("WxButton2"), wxPoint(101, 82), wxSize(86, 32), 0, wxDefaultValidator, _("WxButton2"));
 WxBoxSizer1->Add(WxButton2, 1, wxALIGN_TOP | wxALL, 5);

 WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
 WxBoxSizer1->Add(WxBoxSizer2, 1, wxEXPAND | wxALL, 5);

 WxEdit1 = new wxTextCtrl(this, wxID_ANY, _("WxEdit1"), wxPoint(12, 5), wxSize(139, 32), 0, wxDefaultValidator, _("WxEdit1"));
 WxBoxSizer2->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

 WxButton3 = new wxButton(this, wxID_ANY, _("WxButton3"), wxPoint(38, 37), wxSize(107, 32), 0, wxDefaultValidator, _("WxButton3"));
 WxBoxSizer2->Add(WxButton3, 0, wxALIGN_CENTER | wxALL, 5);

 WxMemo1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(5, 76), wxSize(153, 102), wxTE_MULTILINE, wxDefaultValidator, _("WxMemo1"));
 WxMemo1->SetMaxLength(0);
 WxMemo1->AppendText(_("WxMemo1"));
 WxMemo1->SetFocus();
 WxMemo1->SetInsertionPointEnd();
 WxBoxSizer2->Add(WxMemo1, 1, wxALIGN_CENTER | wxALL, 5);



 Layout();
 GetSizer()->SetSizeHints(this);
 Center();
}