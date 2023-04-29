#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_button1_click( wxCommandEvent& event )
{
// TODO: Implement m_button1_click
}

void GUIMyFrame1::m_button2_click( wxCommandEvent& event )
{
// TODO: Implement m_button2_click
}

void GUIMyFrame1::m_button3_click( wxCommandEvent& event )
{
// TODO: Implement m_button3_click
}

void GUIMyFrame1::m_button4_click( wxCommandEvent& event )
{
// TODO: Implement m_button4_click
}

void GUIMyFrame1::m_cb_color_click( wxCommandEvent& event )
{
// TODO: Implement m_cb_color_click
}

void GUIMyFrame1::m_s_rotation_onscroll( wxScrollEvent& event )
{
	m_st_rotation->SetLabel(wxString::Format("Obrot: %d stopni.",m_s_rotation->GetValue()));
}

void GUIMyFrame1::m_s_tilt_onscroll( wxScrollEvent& event )
{
// TODO: Implement m_s_tilt_onscroll
}
