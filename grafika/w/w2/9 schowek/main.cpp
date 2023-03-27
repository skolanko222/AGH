#include <wx/wxprec.h>
#include <wx/clipbrd.h>

int random(int v)
{
 return int(v*float(rand()) / RAND_MAX);
}

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
 wxButton *WxButton3;
 wxButton *WxButton2;
 wxButton *WxButton1;
 wxBoxSizer *WxBoxSizer2;
 wxPanel *WxPanel1;
 wxBoxSizer *WxBoxSizer1;

 void WxButton1_Click(wxCommandEvent &e);
 void WxButton2_Click(wxCommandEvent &e);
 void WxButton3_Click(wxCommandEvent &e);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
//  SetProcessDPIAware();
 MyFrame *frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 09")
{
 SetTitle(_("Demo 09 - Wykorzystanie schowka"));
 SetIcon(wxNullIcon);
 Center();

 WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
 this->SetSizer(WxBoxSizer1);
 this->SetAutoLayout(true);

 WxPanel1 = new wxPanel(this, wxID_ANY, wxPoint(5, 39), wxSize(213, 47));
 WxBoxSizer1->Add(WxPanel1, 1, /*wxALIGN_CENTER |*/ wxEXPAND | wxALL, 5);

 WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
 WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

 WxButton1 = new wxButton(this, wxID_ANY, _("Rysuj"), wxPoint(5, 5), wxSize(86, 29), 0, wxDefaultValidator, _("WxButton1"));
 WxBoxSizer2->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

 WxButton2 = new wxButton(this, wxID_ANY, _("Kopiuj"), wxPoint(5, 44), wxSize(86, 29), 0, wxDefaultValidator, _("WxButton2"));
 WxBoxSizer2->Add(WxButton2, 0, wxALIGN_CENTER | wxALL, 5);

 WxButton3 = new wxButton(this, wxID_ANY, _("Wstaw"), wxPoint(5, 83), wxSize(86, 28), 0, wxDefaultValidator, _("WxButton3"));
 WxBoxSizer2->Add(WxButton3, 0, wxALIGN_CENTER | wxALL, 5);

 Layout();
 GetSizer()->SetSizeHints(this);
 Center();
 
 WxButton1->Bind(wxEVT_BUTTON, &MyFrame::WxButton1_Click, this);
 WxButton2->Bind(wxEVT_BUTTON, &MyFrame::WxButton2_Click, this);
 WxButton3->Bind(wxEVT_BUTTON, &MyFrame::WxButton3_Click, this);
}

void MyFrame::WxButton1_Click(wxCommandEvent &e)
{
 int w, h, r, i, x, y;
 wxClientDC MyDC(WxPanel1);
 WxPanel1->GetClientSize(&w, &h);
 MyDC.Clear();
 for (i = 0; i<100; i++)
 {
  x = random(w);
  y = random(h);
  r = random(50);
  MyDC.SetBrush(wxBrush(wxColour(random(255), random(255), random(255))));
  MyDC.DrawCircle(x, y, r);
 }
}

void MyFrame::WxButton2_Click(wxCommandEvent &e)
{
 int w, h;
 wxClientDC MyDC(WxPanel1);
 wxMemoryDC MyBitmapDC;
 WxPanel1->GetClientSize(&w, &h);
 wxBitmap MyBitmap(w, h,24);
 MyBitmapDC.SelectObject(MyBitmap);
 MyBitmapDC.Blit(0, 0, w, h, &MyDC, 0, 0);

 if (wxTheClipboard->Open())  // #include <wx/clipbrd.h>
 {
  wxTheClipboard->SetData(new wxBitmapDataObject(MyBitmap));
  wxTheClipboard->Close();
 }

 //if (wxTheClipboard->Open())
 //{
 //    wxTheClipboard->SetData(new wxTextDataObject("Tekst tez moze byc..."));
 //    wxTheClipboard->Close();
 //}
 }

void MyFrame::WxButton3_Click(wxCommandEvent &e)
{
 int w, h;
 wxClientDC MyDC(WxPanel1);
 wxMemoryDC MyBitmapDC;
 WxPanel1->GetClientSize(&w, &h);
 wxBitmap MyBitmap(w, h);

 if (wxTheClipboard->Open())
 {
  if (wxTheClipboard->IsSupported(wxDF_BITMAP))
  {
   wxBitmapDataObject data;
   wxTheClipboard->GetData(data);
   MyBitmap = data.GetBitmap();
  }
  wxTheClipboard->Close();
 }

 MyBitmapDC.SelectObject(MyBitmap);
 MyDC.Blit(0, 0, w, h, &MyBitmapDC, 0, 0);
}