#ifndef __NieModalnyDlg_h__
#define __NieModalnyDlg_h__

#include "MyFrame.h"
extern class MyFrame *frame;

class NieModalnyDlg : public wxDialog
{
private:
 wxButton *WxButton1;
 wxScrollBar *WxScrollBar1;
public:
 NieModalnyDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = _("NieModalny"),
  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
  long style = wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX);
 void WxButton1Click(wxCommandEvent& event) { Close(); }
 void OnClose(wxCloseEvent& event) { Destroy(); }
 void WxScrollBar1Scroll(wxScrollEvent &e);
};

#endif
