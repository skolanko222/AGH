///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <memory>
#include <wx/wxprec.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/colordlg.h>
#include <wx/textctrl.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/filefn.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:
	void wxButton_kolor(wxCommandEvent& e);
	void Form_Paint(wxPaintEvent& e);
	void Form_Update(wxUpdateUIEvent& e);
	void wxCheckbox(wxCommandEvent& e);
	void wxGaug(wxScrollEvent& e);
	void wxText(wxCommandEvent& e);
	void draw();
	void save(wxCommandEvent& e);


	enum {
		ID_WXBUTTON_ZAPIS = 1001,
		ID_WXCHECKBOX = 1002,
		ID_WXSCROLLBAR = 1003,
		ID_WXGAUGE = 1004,
		ID_WXBUTTON_KOLOR = 1005,
		ID_WXCHOICE = 1006,
		ID_WXTEXT = 1007,
		
	};


	wxPoint star[5] = {
			wxPoint(-90, -105),
			wxPoint(-75, -65),
			wxPoint(-110, -90),
			wxPoint(-70, -90),
			wxPoint(-105, -65)
	};


	wxString text = "tekst";
	wxColour kolor = wxColour(*wxBLACK);
	wxBitmap buffer;
	wxImage bananImage;
	wxBitmap bananBitmap;
	wxImage toSave;

protected:
	wxPanel* panel1;
	wxButton* zapis;
	wxCheckBox* checkbox;
	wxScrollBar* scrollbar;
	wxGauge* gauge;
	wxButton* kolor_g;
	wxChoice* wybor;
	wxTextCtrl* textctrlText;

public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Lab 03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(600, 400), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};

