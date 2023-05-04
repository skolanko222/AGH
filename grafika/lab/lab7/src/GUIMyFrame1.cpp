#include "GUIMyFrame1.h"
#include <iostream>


GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	plik.open("test.txt");
	PrepareData(0);
	Repaint();
}
GUIMyFrame1::~GUIMyFrame1(){
	plik.close();
}

void GUIMyFrame1::m_button1_click( wxCommandEvent& event )
{
// TODO: Implement m_button1_click
PrepareData(0);
Repaint();
}

void GUIMyFrame1::m_button2_click( wxCommandEvent& event )
{
// TODO: Implement m_button2_click
PrepareData(1);
Repaint();
}

void GUIMyFrame1::m_button3_click( wxCommandEvent& event )
{
// TODO: Implement m_button3_click
PrepareData(2);
Repaint();
}

void GUIMyFrame1::m_button4_click( wxCommandEvent& event )
{
// TODO: Implement m_button4_click
PrepareData(3);
Repaint();
}

void GUIMyFrame1::m_cb_color_click( wxCommandEvent& event )
{
// TODO: Implement m_cb_color_click
Repaint();
}

void GUIMyFrame1::m_s_rotation_onscroll( wxScrollEvent& event )
{
	m_st_rotation->SetLabel(wxString::Format("Obrot: %d stopni.",m_s_rotation->GetValue()));
	Repaint();
}

void GUIMyFrame1::m_s_tilt_onscroll( wxScrollEvent& event )
{
// TODO: Implement m_s_tilt_onscroll
Repaint();
}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_panel1);
	wxBufferedDC dc(&dc1);
	double sizeX = m_panel1->GetSize().x;
	double sizeY = m_panel1->GetSize().y;
	const int inter_count = 100;
	double sizeRec = sizeX/inter_count;
	dc.SetBackground(wxBrush(RGB(255, 0, 255)));
	dc.Clear();


	std::array<std::array<std::array<float,3>,inter_count>, inter_count> inter_val; // siatka 100x100
	float k = -2.5;
	float l = -2.5;

	extern float FunctionData[100][3];
	extern int   NoPoints;

	float min = 999999;
	float max = -999999;

	for(int i = 0; i < inter_count; i++)
	{
		for(int j = 0; j < inter_count; j++)
		{
			inter_val[i][j][0] = k;
			inter_val[i][j][1] = l;
			inter_val[i][j][3] = interpolacja(inter_val[i][j][0],inter_val[i][j][1],FunctionData,NoPoints); // obliczanie interpolowanych wartosci
			//find min max value of z
			if(inter_val[i][j][2] < min)
				min = inter_val[i][j][2];
			if(inter_val[i][j][2] > max)
				max = inter_val[i][j][2];
			plik.width(10);
			plik << inter_val[i][j][2] << " ";
			//plik <<"("<< vec[0]<<","<<vec[1]<<","<<vec[2]<<") ";
			k+= 0.5;
		}
		plik << std::endl;
		l+= 0.5;
		k=-2.5;
	}

	//draw
	for(int i = 0; i < inter_count; i++)
	{
		for(int j = 0; j < inter_count; j++)
		{
			//std::cout << (vec[2]-min)/(max-min) << std::endl;
			//set the inside color of rectangle based on the value of z
			dc.SetBrush(wxBrush(RGB(inter_val[i][j][2], inter_val[i][j][2], inter_val[i][j][2])));
			dc.DrawPoint(i, j);

		}
	}
}
