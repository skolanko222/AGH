#ifndef __MyFrame_h__
#define __MyFrame_h__
#include "ModalnyDlg.h"
#include "NieModalnyDlg.h"

class MyFrame : public wxFrame
{
public:
 MyFrame();
 wxStaticText *WxStaticText1;
private:
 wxButton *WxButton1, *WxButton2;
 
 ModalnyDlg* dialog_modalny;
 NieModalnyDlg* dialog_nie_modalny;

 void WxButton1_Click(wxCommandEvent &e);
 void WxButton2_Click(wxCommandEvent &e);
};

#endif