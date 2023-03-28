///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	Zapis_do_pliku = new wxButton( this, wxID_ANY, wxT("Zapis_do_pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Zapis_do_pliku, 0, wxALL, 5 );

	Banan = new wxCheckBox( this, wxID_ANY, wxT("Banan"), wxDefaultPosition, wxDefaultSize, 0 );
	Banan->SetValue(true);
	bSizer2->Add( Banan, 0, wxALL, 5 );

	slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( slider, 0, wxALL, 5 );

	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 );
	bSizer2->Add( m_gauge1, 0, wxALL, 5 );

	Kolor_gwiazdki = new wxButton( this, wxID_ANY, wxT("Kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Kolor_gwiazdki, 0, wxALL, 5 );

	Pole_tekstowe = new wxTextCtrl( this, wxID_ANY, wxT("Tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Pole_tekstowe, 0, wxALL, 5 );

	wxString Zmiana_ksztaltuChoices[] = { wxT("gwiazdka"), wxT("księżyc"), wxT("słonko") };
	int Zmiana_ksztaltuNChoices = sizeof( Zmiana_ksztaltuChoices ) / sizeof( wxString );
	Zmiana_ksztaltu = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, Zmiana_ksztaltuNChoices, Zmiana_ksztaltuChoices, 0 );
	Zmiana_ksztaltu->SetSelection( 0 );
	bSizer2->Add( Zmiana_ksztaltu, 0, wxALL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	//m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer3->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::Frame1_OnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Frame1_OnUpdateUI ) );
	Zapis_do_pliku->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zapis_do_pliku ), NULL, this );
	Banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::pokaz_banana ), NULL, this );
	slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	Kolor_gwiazdki->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zmien_kolor_gwiazdki ), NULL, this );
	Pole_tekstowe->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::tekst_zmieniony ), NULL, this );
	Zmiana_ksztaltu->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::zmieniono_ksztalt ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::Frame1_OnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::Frame1_OnUpdateUI ) );
	Zapis_do_pliku->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zapis_do_pliku ), NULL, this );
	Banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::pokaz_banana ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::slider_scrolled ), NULL, this );
	Kolor_gwiazdki->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zmien_kolor_gwiazdki ), NULL, this );
	Pole_tekstowe->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::tekst_zmieniony ), NULL, this );
	Zmiana_ksztaltu->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::zmieniono_ksztalt ), NULL, this );

}
