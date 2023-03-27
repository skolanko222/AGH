#include <wx/wxprec.h>
#include <wx/print.h>
#include <wx/printdlg.h>

wxPageSetupDialogData *PageSetupData;

void DrawSomething(wxDC *dc)
{
 dc->Clear();
 dc->DrawRectangle(20, 20, 260, 560);
 dc->DrawRectangle(30, 30, 240, 540);
 dc->DrawCircle(150, 300, 50);
 dc->DrawLine(30, 30, 270, 570);
 dc->DrawLine(270, 30, 30, 570);
}

// ----------------------------------------------------------------------------------------------

class Printout : public wxPrintout
{
 public:
  Printout(const wxString title = wxString("M�j wydruk")) :wxPrintout(title) {};
  bool OnPrintPage(int page);
  bool OnBeginDocument(int startPage, int endPage);
  void GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo);
};

bool Printout::OnBeginDocument(int startPage, int endPage)
{
 if (wxPrintout::OnBeginDocument(startPage, endPage)) return true;
 return false;
}

bool Printout::OnPrintPage(int pageNum)
{
 wxDC *dc = GetDC();
 FitThisSizeToPageMargins(wxSize(300, 600), *PageSetupData);
 DrawSomething(dc);
 return true;
}

void Printout::GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo)
{
 *minPage = 1;
 *maxPage = 1;
 *selPageFrom = 1;
 *selPageTo = 1;
}

// ----------------------------------------------------------------------------------------------

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
 void RightMouseButton_Down(wxMouseEvent &e);
 void Form_Paint(wxPaintEvent &e);
 void MENU_Drukuj_Click(wxCommandEvent &e);
 void MENU_Podglad_Click(wxCommandEvent &e);
 void MENU_Ustawienia_strony_Click(wxCommandEvent &e);

 enum
 {
  ID_MENU_DRUKUJ = 1001,
  ID_MENU_PODGLAD = 1002,
  ID_MENU_USTAWIENIASTRONY = 1003
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

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 10")
{
 SetTitle(_("Demo 10 - Drukowanie"));
 SetIcon(wxNullIcon);
 SetSize(8, 8, 473, 707);
 Center();

 Bind(wxEVT_RIGHT_DOWN, &MyFrame::RightMouseButton_Down, this);
 Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
 Bind(wxEVT_MENU, &MyFrame::MENU_Drukuj_Click, this, ID_MENU_DRUKUJ);
 Bind(wxEVT_MENU, &MyFrame::MENU_Podglad_Click, this, ID_MENU_PODGLAD);
 Bind(wxEVT_MENU, &MyFrame::MENU_Ustawienia_strony_Click, this, ID_MENU_USTAWIENIASTRONY);

 PageSetupData = new wxPageSetupDialogData;
}

void MyFrame::RightMouseButton_Down(wxMouseEvent &e)
{
 wxMenu WxPopupMenu1(_("Menu wydruku"));
 WxPopupMenu1.Append(ID_MENU_DRUKUJ, _("Drukuj"), _(""), wxITEM_NORMAL);
 WxPopupMenu1.Append(ID_MENU_PODGLAD, _("Podgl�d"), _(""), wxITEM_NORMAL);
 WxPopupMenu1.Append(ID_MENU_USTAWIENIASTRONY, _("Ustawienia strony"), _(""), wxITEM_NORMAL);
 PopupMenu(&WxPopupMenu1, e.GetPosition());
}

void MyFrame::Form_Paint(wxPaintEvent& event)
{
 wxPaintDC MyDC(this);
 DrawSomething(&MyDC);
}

void MyFrame::MENU_Drukuj_Click(wxCommandEvent &e)
{
 wxPrinter Printer;
 Printout MyPrintout;
 Printer.Print(this, &MyPrintout, true);
}

void MyFrame::MENU_Podglad_Click(wxCommandEvent &e)
{
 wxPrintPreview preview(new Printout, new Printout);
 wxPreviewFrame frame(&preview, this, wxT("Print"), wxPoint(20, 20), wxSize(400, 600));
 frame.Centre(wxBOTH);
 frame.Initialize();
 frame.Show();
}

void MyFrame::MENU_Ustawienia_strony_Click(wxCommandEvent &e)
{
 wxPageSetupDialog PageSetupDlg(this, PageSetupData);
 PageSetupDlg.ShowModal();
 *PageSetupData = PageSetupDlg.GetPageSetupData();
}