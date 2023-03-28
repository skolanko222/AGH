///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

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
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		// panel do rysowania
		wxPanel* m_panel13;
		// przycisk do zapisu
		wxButton* button_save;
		// czy banan ma byc rysowany
		wxCheckBox* checkbox_banana;
		wxSlider* slider_banana;
		wxGauge* m_gauge2;
		wxButton* btn_star_color_CLICK;
		wxTextCtrl* text_box;
		wxComboBox* combo_box;
		wxFilePickerCtrl* file_picker;

		// Virtual event handlers, override them in your derived class
		virtual void button_save_CLICK( wxCommandEvent& event ) { event.Skip(); }
		virtual void checkbox_banana_CLICK( wxCommandEvent& event ) { event.Skip(); }
		virtual void slider_banana_SCROLL( wxScrollEvent& event ) { event.Skip(); }
		//star color picker
		virtual void button_star_CLICK( wxCommandEvent& event ) { event.Skip(); }
		virtual void combo_box_CLICK( wxCommandEvent& event ) { event.Skip(); }
		virtual void file_picker_CLICK( wxFileDirPickerEvent& event ) { event.Skip(); }


		
		virtual void MainFrameBase_OnPaint(wxPaintEvent& event) { event.Skip(); }
		virtual void MainFrameBase_OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK lab nr 3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 735,653 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

