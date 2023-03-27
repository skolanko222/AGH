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
 wxMenuBar *WxMenuBar1;
 wxTimer *WxTimer1;
 wxCheckBox *WxCheckBox1;
 wxStaticText *WxStaticText1;
 wxCursor MyCursor;

 void Timer1_Timer(wxTimerEvent &e);
 void CheckBox1_Click(wxCommandEvent &e);

 enum
 {
  ID_MENU_PLIK_1004 = 1004,
  ID_MENU_NOWY_1007 = 1007,
  ID_MENU_ZAKONCZ_1009 = 1009,
  ID_MENU_OPCJA_1_1010 = 1010,
  ID_MENU_OPCJA_2_1011 = 1011,
  ID_MENU_WYBOR_A_1013 = 1013,
  ID_MENU_WYBOR_B_1014 = 1014,

  ID_WXTIMER1 = 1002,
  ID_WXCHECKBOX1 = 1003
 };
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
 //SetProcessDPIAware();
 MyFrame *frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 03")
{
 SetTitle(_("Demo 03 - Menu, zasoby i timer"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 730, 471);
 Center();
 
 WxMenuBar1 = new wxMenuBar();
 wxMenu *Menu_Plik = new wxMenu();
 WxMenuBar1->Append(Menu_Plik, _("&Plik"));
 Menu_Plik->Append(ID_MENU_NOWY_1007, _("&Nowy"), _(""), wxITEM_NORMAL);
 Menu_Plik->AppendSeparator();
 Menu_Plik->Append(ID_MENU_ZAKONCZ_1009, _("&Zako�cz"), _(""), wxITEM_NORMAL);
 
 wxMenu *Menu_About = new wxMenu();
 WxMenuBar1->Append(Menu_About, _("&About"));
 Menu_About->Append(ID_MENU_OPCJA_1_1010, _("Opcja &1"), _(""), wxITEM_CHECK);
 Menu_About->Check(ID_MENU_OPCJA_1_1010, true);
 Menu_About->Append(ID_MENU_OPCJA_2_1011, _("Opcja &2"), _(""), wxITEM_CHECK);
 Menu_About->Check(ID_MENU_OPCJA_2_1011, false);
 Menu_About->AppendSeparator();
 Menu_About->Append(ID_MENU_WYBOR_A_1013, _("Wyb�r A"), _(""), wxITEM_RADIO);
 Menu_About->Check(ID_MENU_WYBOR_A_1013, true);
 Menu_About->Append(ID_MENU_WYBOR_B_1014, _("Wyb�r B"), _(""), wxITEM_RADIO);
 Menu_About->Check(ID_MENU_WYBOR_B_1014, false);
 
 SetMenuBar(WxMenuBar1);

 WxTimer1 = new wxTimer();
 WxTimer1->SetOwner(this, ID_WXTIMER1);

 WxCheckBox1 = new wxCheckBox(this, ID_WXCHECKBOX1, _("W��cz &zegarek"), wxPoint(70, 273), wxSize(142, 25), 0, wxDefaultValidator, _("WxCheckBox1"));

 WxStaticText1 = new wxStaticText(this, wxID_ANY, _("WxStaticText1"), wxPoint(125, 152), wxDefaultSize, 0, _("WxStaticText1"));
 WxStaticText1->SetFont(wxFont(25, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _("Tahoma")));

 this->Bind(wxEVT_MENU, [&, this](wxCommandEvent &) { WxStaticText1->SetLabel("Wybrano: NOWY"); }, ID_MENU_NOWY_1007);
 this->Bind(wxEVT_MENU, [&, this](wxCommandEvent &) { Close(); }, ID_MENU_ZAKONCZ_1009);
 Bind(wxEVT_TIMER, &MyFrame::Timer1_Timer, this, ID_WXTIMER1);
 Bind(wxEVT_CHECKBOX, &MyFrame::CheckBox1_Click, this, ID_WXCHECKBOX1);
}

void MyFrame::Timer1_Timer(wxTimerEvent &e)
{
 wxDateTime now = wxDateTime::Now();
 WxStaticText1->SetLabel(wxString::Format("%d",now.GetHour()) + ":" + wxString::Format("%02d", now.GetMinute()) + ":" + wxString::Format("%02d", now.GetSecond()));
}

void MyFrame::CheckBox1_Click(wxCommandEvent &e)
{
 if (WxCheckBox1->IsChecked())
 {
  WxTimer1->Start(100);
  MyCursor = wxCursor("my_cursor.cur", wxBITMAP_TYPE_CUR,26,0);
  SetCursor(MyCursor);
 }
 else
 {
  WxTimer1->Stop();
  MyCursor = wxCursor(*wxSTANDARD_CURSOR);
  SetCursor(MyCursor);
 }
}
