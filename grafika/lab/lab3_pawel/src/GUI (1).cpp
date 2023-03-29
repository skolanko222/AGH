///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer(wxVERTICAL);

	panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	bSizer6->Add(panel1, 1, wxEXPAND | wxALL, 5);


	bSizer4->Add(bSizer6, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer(wxVERTICAL);

	zapis = new wxButton(this, ID_WXBUTTON_ZAPIS, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(zapis, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	checkbox = new wxCheckBox(this, ID_WXCHECKBOX, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(checkbox, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
	
	scrollbar = new wxScrollBar(this, ID_WXSCROLLBAR, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL);
	scrollbar->Disable();
	scrollbar->SetScrollbar(0, 0, 100, 1);
	bSizer5->Add(scrollbar, 0, wxALL | wxEXPAND, 5);

	gauge = new wxGauge(this, ID_WXGAUGE, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	gauge->SetValue(0);
	bSizer5->Add(gauge, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	kolor_g = new wxButton(this, ID_WXBUTTON_KOLOR, wxT("kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(kolor_g, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	textctrlText = new wxTextCtrl(this, ID_WXTEXT, text, wxDefaultPosition, wxDefaultSize, 0);
	bSizer5->Add(textctrlText, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	wxString wyborChoices[] = { wxT("gwiazdka"), wxT("ksiezyc"), wxT("slonko") };
	int wyborNChoices = sizeof(wyborChoices) / sizeof(wxString);
	wybor = new wxChoice(this, ID_WXCHOICE, wxDefaultPosition, wxDefaultSize, wyborNChoices, wyborChoices, 0);
	wybor->SetSelection(0);
	bSizer5->Add(wybor, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer4->Add(bSizer5, 0, wxEXPAND, 5);


	this->SetSizer(bSizer4);
	this->Layout();

	this->Centre(wxBOTH);

	/////////////////////////////////////////////////////////////////////////////////////////////

	bananImage.AddHandler(new wxPNGHandler);
	bananImage.LoadFile("banan1.png", wxBITMAP_TYPE_PNG);
	bananBitmap = wxBitmap(bananImage);

	Bind(wxEVT_BUTTON, &MyFrame1::wxButton_kolor, this, ID_WXBUTTON_KOLOR);
	Bind(wxEVT_PAINT, &MyFrame1::Form_Paint, this);
	Bind(wxEVT_UPDATE_UI, &MyFrame1::Form_Update, this);
	Bind(wxEVT_CHECKBOX, &MyFrame1::wxCheckbox, this, ID_WXCHECKBOX);
	Bind(wxEVT_SCROLL_THUMBTRACK, &MyFrame1::wxGaug, this, ID_WXSCROLLBAR);
	Bind(wxEVT_TEXT, &MyFrame1::wxText, this, ID_WXTEXT);
	Bind(wxEVT_BUTTON, &MyFrame1::save, this, ID_WXBUTTON_ZAPIS);
}

MyFrame1::~MyFrame1()
{
}

void MyFrame1::wxButton_kolor(wxCommandEvent& e) {
	wxColourDialog chooseColourDialog(this, nullptr);
	if (chooseColourDialog.ShowModal() == wxID_CANCEL)
		return;
	kolor = chooseColourDialog.GetColourData().GetColour();
}

void MyFrame1::Form_Paint(wxPaintEvent& e) {
	draw();
}

void MyFrame1::Form_Update(wxUpdateUIEvent& e) {
	draw();
}

void MyFrame1::wxCheckbox(wxCommandEvent& e) {
	scrollbar->Enable(checkbox->IsChecked());
}

void MyFrame1::wxGaug(wxScrollEvent& e) {
	gauge->SetValue(scrollbar->GetThumbPosition());
	draw();
}

void MyFrame1::wxText(wxCommandEvent& e) {
	text = textctrlText->GetValue();
}

void MyFrame1::save(wxCommandEvent& e) {
	wxFileDialog filedialog(this, "Save your file", "", "", "All files (*.*)|*.*", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (filedialog.ShowModal() == wxID_CANCEL)
		return;
	toSave = buffer.ConvertToImage();
	toSave.AddHandler(new wxPNGHandler);
	toSave.AddHandler(new wxJPEGHandler);
	toSave.SaveFile(filedialog.GetPath());
}

void MyFrame1::draw() {
	std::unique_ptr<wxClientDC> client_dc(new wxClientDC(panel1));
	buffer = wxBitmap(panel1->GetSize());
	std::unique_ptr<wxBufferedDC> myDC(new wxBufferedDC(client_dc.get(), buffer));

	myDC->SetDeviceOrigin((panel1->GetSize().x)/2, (panel1->GetSize().y)/2);
	myDC->SetBackground(*wxWHITE_BRUSH);
	myDC->Clear();

	myDC->DrawText(text, -100, 90);
	myDC->SetFont(wxFont(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Magneto"));
	myDC->DrawRotatedText(text, 100, 90, 90);

	myDC->DrawLine(0, 0, 0, -10); //tulow
	myDC->DrawLine(0, 0, 0, 60);
	myDC->DrawLine(0, 60, 30, 90); //nogi
	myDC->DrawLine(0, 60, -30, 90);
	myDC->DrawLine(0, 0, 45, 15); //rece
	double y = 15 - (scrollbar->GetThumbPosition()) * 3 / 10;
	double R = sqrt(45 * 45 + 15 * 15);
	double x = sqrt(R * R - y * y);
	myDC->DrawLine(0, 0, -x, y);

	myDC->DrawCircle(0, -30, 20);  //glowa
	myDC->DrawEllipse(-13, -38, 10, 7); //oko

	if (checkbox->IsChecked()) {
		myDC->DrawEllipticArc(-9, -28, 20, 10, 180, 360);
		myDC->DrawEllipse(4, -38, 10, 7);
		myDC->DrawBitmap(bananBitmap, -x-bananBitmap.GetWidth()/2, y-bananBitmap.GetHeight()/2, true);
	}
	else {
		myDC->DrawEllipticArc(-9, -25, 20, 10, 0, 180);
		myDC->DrawEllipse(5, -40, 7, 10); 
	}

	if (wybor->GetSelection() == 0) {
		myDC->SetBrush(kolor);
		myDC->SetPen(kolor);
		myDC->DrawPolygon(5, star);
	}
	else if (wybor->GetSelection() == 1) {
		myDC->SetBrush(*wxLIGHT_GREY_BRUSH);
		myDC->SetPen(*wxLIGHT_GREY_PEN);
		myDC->DrawCircle(-100, -100, 20);
		myDC->SetBrush(*wxWHITE_BRUSH);
		myDC->SetPen(*wxWHITE_PEN);
		myDC->DrawCircle(-107, -107, 16);
		myDC->SetBrush(*wxBLACK_BRUSH);
		myDC->SetPen(*wxBLACK_PEN);
		myDC->DrawCircle(-90, -100, 2);
		myDC->DrawLine(-99, -91, -95, -88);
	}
	else {
		myDC->SetBrush(*wxYELLOW_BRUSH);
		myDC->SetPen(*wxYELLOW_PEN);
		myDC->DrawCircle(-100, -100, 20);
	}
}