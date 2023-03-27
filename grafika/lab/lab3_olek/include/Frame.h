///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-282-g1fa54006)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <memory>
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
#include <wx/slider.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/filepicker.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame1
///////////////////////////////////////////////////////////////////////////////
class Frame1 : public wxFrame
{
	private:

	protected:
		wxPanel* panel1;
		wxButton* button_zapisz;
		wxCheckBox* checkbox_banan;
		wxSlider* slider_banan;
		wxGauge* gauge_banan;
		wxButton* button_color;
		wxTextCtrl* tekst;
		wxComboBox* comboBox_star;
		wxFilePickerCtrl* file_picker;

		// Virtual event handlers, override them in your derived class
		virtual void Frame1_OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void Frame1_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnClickSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCheckBanana( wxCommandEvent& event ) { event.Skip(); }
		virtual void Onscroll_banan( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnClickColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void comboBox_star_OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilePicker( wxFileDirPickerEvent& event ) { event.Skip(); }


	public:

		Frame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("lab 3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Frame1();

};

