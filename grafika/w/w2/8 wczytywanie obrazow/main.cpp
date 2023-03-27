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
 wxButton *WxButton1;
 wxButton *WxButton2;
 wxBitmap MyBitmap;
 wxImage  MyImage;

 void Form_Paint(wxPaintEvent &e);
 void WxButton1_Click(wxCommandEvent &e);
 void WxButton2_Click(wxCommandEvent &e);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
 //SetProcessDPIAware();
 MyFrame *frame = new MyFrame();
 frame->Show(true);
 return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 08")
{
 SetTitle(_("Demo 08 - Obs�uga BMP i JPG"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 437, 596);
 Center();

 WxButton1 = new wxButton(this, wxID_ANY, _("Wczytaj BMP"), wxPoint(23, 503), wxSize(121, 29), 0, wxDefaultValidator, _("WxButton1"));
 WxButton2 = new wxButton(this, wxID_ANY, _("Zapisz JPG"), wxPoint(261, 503), wxSize(129, 29), 0, wxDefaultValidator, _("WxButton2"));
 
 Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
 WxButton1->Bind(wxEVT_BUTTON, &MyFrame::WxButton1_Click, this);
 WxButton2->Bind(wxEVT_BUTTON, &MyFrame::WxButton2_Click, this);

 MyImage.AddHandler(new wxJPEGHandler);
 MyImage.AddHandler(new wxPNGHandler);
}

void MyFrame::WxButton1_Click(wxCommandEvent &e)
{
 wxString filename;
 wxFileDialog WxOpenFileDialog1(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
 WxOpenFileDialog1.SetWildcard("BMP files (*.bmp)|*.bmp");
 if (WxOpenFileDialog1.ShowModal() == wxID_OK)
 {
  filename = WxOpenFileDialog1.GetPath();

  if (!MyImage.LoadFile(filename, wxBITMAP_TYPE_BMP))
   wxLogError(_("Nie mo�na za�adowa obrazka"));
  else
  {
   wxImage TempImg(MyImage);
   TempImg.Rescale(120, 80);
   MyImage.Paste(TempImg, MyImage.GetWidth() - 120, 0);
   MyBitmap = wxBitmap(MyImage);
  }
  if (MyBitmap.Ok()) this->SetTitle(filename);
  Refresh();
 }
}

void MyFrame::Form_Paint(wxPaintEvent &e)
{
 wxPaintDC dc(this);
 PrepareDC(dc);
 if (MyBitmap.Ok()) dc.DrawBitmap(MyBitmap, 20, 20);
}

void MyFrame::WxButton2_Click(wxCommandEvent &e)
{
 MyImage.SaveFile("test-out.bmp");
 MyImage.SetOption("quality", 5);
 MyImage.SaveFile("test-out.jpg");
 MyImage.SaveFile("test-out.png");
 //MyBitmap.SaveFile("Btest-out.bmp",wxBITMAP_TYPE_BMP);
 //MyBitmap.SaveFile("Btest-out.jpg",wxBITMAP_TYPE_JPEG);
 //MyBitmap.SaveFile("Btest-out.png",wxBITMAP_TYPE_PNG);
}