///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-282-g1fa54006)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Frame.h"

///////////////////////////////////////////////////////////////////////////

Frame1::Frame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxDefaultSize );

	wxBoxSizer* Sizer1;
	Sizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* Sizer2;
	Sizer2 = new wxBoxSizer( wxVERTICAL );

	panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	//panel1->SetBackgroundColour( /*wxTRANSPARENT*/wxColour( 255, 255, 255 ) );

	Sizer2->Add( panel1, 1, wxEXPAND | wxALL, 5 );


	Sizer1->Add( Sizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* Sizer3;
	Sizer3 = new wxBoxSizer( wxVERTICAL );

	Sizer3->SetMinSize( wxSize( 150,-1 ) );
	button_zapisz = new wxButton( this, wxID_ANY, wxT("Save to file"), wxDefaultPosition, wxDefaultSize, 0 );
	Sizer3->Add( button_zapisz, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	checkbox_banan = new wxCheckBox( this, wxID_ANY, wxT("Banan"), wxDefaultPosition, wxDefaultSize, 0 );
	Sizer3->Add( checkbox_banan, 0, wxALIGN_CENTER|wxALL, 5 );

	slider_banan = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	slider_banan->Enable( false );

	Sizer3->Add( slider_banan, 0, wxALIGN_CENTER|wxALL, 5 );

	gauge_banan = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 100,-1 )/*wxDefaultSize*/, wxGA_HORIZONTAL );
	gauge_banan->SetValue( 0 );
	Sizer3->Add( gauge_banan, 0, wxALIGN_CENTER|wxALL, 5 );

	button_color = new wxButton( this, wxID_ANY, wxT("Kolor"), wxDefaultPosition, wxDefaultSize, 0 );
	Sizer3->Add( button_color, 0, wxALIGN_CENTER|wxALL, 5 );

	tekst = new wxTextCtrl( this, wxID_ANY, wxT("text"), wxDefaultPosition, wxDefaultSize, 0 );
	Sizer3->Add( tekst, 0, wxALIGN_CENTER|wxALL, 5 );

	comboBox_star = new wxComboBox( this, wxID_ANY, wxT("gwiazda"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	comboBox_star->Append( wxT("księżyc") );
	comboBox_star->Append( wxT("słońce") );
	comboBox_star->Append( wxT("gwiazda") );
	comboBox_star->SetSelection( 2 );
	Sizer3->Add( comboBox_star, 0, wxALIGN_CENTER|wxALL, 5 );

	file_picker = new wxFilePickerCtrl( this, wxID_ANY, wxEmptyString, wxT("Wybierz plik"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, 0 );
	file_picker->Hide();

	Sizer3->Add( file_picker, 0, wxALL, 5 );


	Sizer1->Add( Sizer3, 0, wxEXPAND|wxRIGHT, 5 );


	this->SetSizer( Sizer1 );
	this->Layout();

	this->Centre( wxBOTH );
	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( Frame1::Frame1_OnPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame1::Frame1_OnUpdateUI ) );
	button_zapisz->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame1::OnClickSave ), NULL, this );
	checkbox_banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Frame1::OnClickCheckBanana ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	button_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame1::OnClickColor ), NULL, this );
	comboBox_star->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Frame1::comboBox_star_OnCombobox ), NULL, this );
	file_picker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Frame1::OnFilePicker ), NULL, this );
}

Frame1::~Frame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( Frame1::Frame1_OnPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame1::Frame1_OnUpdateUI ) );
	button_zapisz->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame1::OnClickSave ), NULL, this );
	checkbox_banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Frame1::OnClickCheckBanana ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	slider_banan->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame1::Onscroll_banan ), NULL, this );
	button_color->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame1::OnClickColor ), NULL, this );
	comboBox_star->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( Frame1::comboBox_star_OnCombobox ), NULL, this );
	file_picker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Frame1::OnFilePicker ), NULL, this );

}
