///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.hpp"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_panel13 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	//m_panel13->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	bSizer6->Add( m_panel13, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	button_save = new wxButton( m_panel2, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( button_save, 0, wxALIGN_CENTER|wxALL, 5 );

	checkbox_banana = new wxCheckBox( m_panel2, wxID_ANY, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( checkbox_banana, 0, wxALIGN_CENTER|wxALL, 5 );

	slider_banana = new wxSlider( m_panel2, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer5->Add( slider_banana, 0, wxEXPAND|wxALL, 5 );

	m_gauge2 = new wxGauge( m_panel2, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge2->SetValue( 0 );
	bSizer5->Add( m_gauge2, 0, wxALIGN_CENTER|wxALL, 5 );

	btn_star_color_CLICK = new wxButton( m_panel2, wxID_ANY, wxT("kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( btn_star_color_CLICK, 0, wxALIGN_CENTER|wxALL, 5 );

	text_box = new wxTextCtrl( m_panel2, wxID_ANY, wxT("sdsdsda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( text_box, 0, wxALIGN_CENTER|wxALL, 5 );

	combo_box = new wxComboBox( m_panel2, wxID_ANY, wxT("87"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	combo_box->Append( wxT("gwiazda") );
	combo_box->Append( wxT("słońce") );
	combo_box->Append( wxT("księżyc") );
	combo_box->SetSelection( 2 );
	bSizer5->Add( combo_box, 0, wxALIGN_CENTER|wxALL, 5 );

	file_picker = new wxFilePickerCtrl( m_panel2, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	file_picker->Hide();

	bSizer5->Add( file_picker, 0, wxALL, 5 );


	m_panel2->SetSizer( bSizer5 );
	m_panel2->Layout();
	bSizer5->Fit( m_panel2 );
	bSizer12->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer8->Add( bSizer12, 0, wxEXPAND, 5 );


	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MainFrameBase_OnPaint ), NULL, this  );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::MainFrameBase_OnUpdateUI ), NULL, this  );
	button_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_save_CLICK ), NULL, this );
	checkbox_banana->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::checkbox_banana_CLICK ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	btn_star_color_CLICK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_star_CLICK ), NULL, this );
	combo_box->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame::combo_box_CLICK ), NULL, this );
	file_picker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrame::file_picker_CLICK ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame::MainFrameBase_OnPaint ), NULL, this  );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::MainFrameBase_OnUpdateUI ), NULL, this  );
	button_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_save_CLICK ), NULL, this );
	checkbox_banana->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::checkbox_banana_CLICK ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	slider_banana->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::slider_banana_SCROLL ), NULL, this );
	btn_star_color_CLICK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::button_star_CLICK ), NULL, this );
	combo_box->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame::combo_box_CLICK ), NULL, this );
	file_picker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( MyFrame::file_picker_CLICK ), NULL, this );

}
