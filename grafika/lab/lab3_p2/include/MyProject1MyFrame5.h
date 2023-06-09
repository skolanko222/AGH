#pragma once
#include <math.h>
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
/**
@file
Subclass of MyFrame5, which is generated by wxFormBuilder.
*/


//// end generated include

/** Implementing MyFrame5 */
#include "noname.h"

wxColour color;
wxPen pen;
class MyProject1MyFrame5 : public MyFrame5
{
  protected:
	// Handlers for MyFrame5 events.
	void m_button30OnButtonClick(wxCommandEvent &event);
	void m_slider2OnScroll(wxScrollEvent &event);
	void m_checkBox1OnCheckBox(wxCommandEvent &event);
	void m_colourPicker3OnColourChanged(wxColourPickerEvent &event);
	void m_textCtrl3OnText(wxCommandEvent &event);
	void m_choice4OnChoice(wxCommandEvent &event);
	void Form_Paint(wxPaintEvent &e);

	int smile_angle = 180;
	int hand_radius_t_ = 0;
	int right_hand_x = 240;
	int right_hand_y = 180;

	wxFileDialog *WxOpenFileDialog1;
	wxFileDialog *wxSaveFileDialog;

	wxBitmap _banan;
	wxBitmap _pic;
	wxImage MyImage;

	bool _banana_draw_flag = 0;
	bool polygons = 0;
	bool moon = 0;
	bool sun = 0;

	int m_panel_x = m_panel2->GetSize().x;
	int m_panel_y = m_panel2->GetSize().y;
	wxString text;

  public:
	/** Constructor */
	MyProject1MyFrame5(wxWindow *parent);
	//// end generated class members
};
