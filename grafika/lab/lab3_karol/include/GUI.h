///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once
#include <memory>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* Zapis_do_pliku;
		wxCheckBox* Banan;
		wxSlider* slider;
		wxGauge* m_gauge1;
		wxButton* Kolor_gwiazdki;
		wxTextCtrl* Pole_tekstowe;
		wxChoice* Zmiana_ksztaltu;
		wxPanel* m_panel1;

		// Virtual event handlers, override them in your derived class
		virtual void zapis_do_pliku( wxCommandEvent& event ) { event.Skip(); }
		virtual void pokaz_banana( wxCommandEvent& event ) { event.Skip(); }
		virtual void slider_scrolled( wxScrollEvent& event ) { event.Skip(); }
		virtual void zmien_kolor_gwiazdki( wxCommandEvent& event ) { event.Skip(); }
		virtual void tekst_zmieniony( wxCommandEvent& event ) { event.Skip(); }
		virtual void zmieniono_ksztalt( wxCommandEvent& event ) { event.Skip(); }
		virtual void Frame1_OnPaint(wxPaintEvent & event){event.Skip();}
		virtual void Frame1_OnUpdateUI(wxUpdateUIEvent & event){event.Skip();}


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

