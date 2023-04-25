#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>
#include "vecmat.h"
#include <iostream>
#include <cmath>

struct Point
{
	float x, y, z;
	Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Color
{
	int R, G, B;
	Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};

struct Segment
{
	Point begin, end;
	Color color;
	Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};

std::vector<Segment> data;
Matrix4 Translate(Matrix4 m, double tx, double ty, double tz) {
    m.data[0][0] = 1;
    m.data[0][3] = tx;
    m.data[1][1] = 1;
    m.data[1][3] = ty;
    m.data[2][2] = 1;
    m.data[2][3] = tz;
    m.data[3][3] = 1;
    return m;
}

Matrix4 RotateX(double angle) {
    Matrix4 m;
    m.data[0][0] = 1;
    m.data[1][1] = cos(angle);
    m.data[1][2] = -sin(angle);
    m.data[2][1] = sin(angle);
    m.data[2][2] = cos(angle);
    m.data[3][3] = 1;
    return m;
}

Matrix4 RotateY(double angle) {
    Matrix4 m;
    m.data[0][0] = cos(angle);
    m.data[0][2] = sin(angle);
    m.data[1][1] = 1;
    m.data[2][0] = -sin(angle);
    m.data[2][2] = cos(angle);
    m.data[3][3] = 1;
    return m;
}

Matrix4 RotateZ(double angle) {
    Matrix4 m;
    m.data[0][0] = cos(angle);
    m.data[0][1] = -sin(angle);
    m.data[1][0] = sin(angle);
    m.data[1][1] = cos(angle);
    m.data[2][2] = 1;
    m.data[3][3] = 1;
    return m;
}

Matrix4 Scale(Matrix4& m, double sx, double sy, double sz) {
    m.data[0][0] = sx;
    m.data[1][1] = sy;
    m.data[2][2] = sz;
    m.data[3][3] = 1;
    return m;
}
Matrix4 GetMatrix(Vector4 translation, Vector4 rotation, Vector4 scale) {
    Matrix4 m;
    m = Translate(m, translation.GetX(), translation.GetY(), translation.GetZ());
    m = Scale(m, scale.GetX(), scale.GetY(), scale.GetZ());
    m = m*RotateX(rotation.GetX());
    m = m*RotateY(rotation.GetY());
    m = m*RotateZ(rotation.GetZ());
    return m;
}

Matrix4 Projection(double d,double wh,double a,double b) {
    Matrix4 m;
    m.data[0][0] = d / wh;
    m.data[1][1] = d / wh;
    m.data[2][2] = (a + b) / (a - b);
    m.data[2][3] = 2 * a * b / (a - b);
    m.data[3][2] = -1;
    m.data[3][3] = 0;
    return m;
}

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent)
{
	m_button_load_geometry->SetLabel(_("Wczytaj Geometrie"));
	m_staticText25->SetLabel(_("Obrot X:"));
	m_staticText27->SetLabel(_("Obrot Y:"));
	m_staticText29->SetLabel(_("Obrot Z:"));

	WxSB_TranslationX->SetRange(0, 200); WxSB_TranslationX->SetValue(100);
	WxSB_TranslationY->SetRange(0, 200); WxSB_TranslationY->SetValue(100);
	WxSB_TranslationZ->SetRange(0, 200); WxSB_TranslationZ->SetValue(100);

	WxSB_RotateX->SetRange(0, 360); WxSB_RotateX->SetValue(0);
	WxSB_RotateY->SetRange(0, 360); WxSB_RotateY->SetValue(0);
	WxSB_RotateZ->SetRange(0, 360); WxSB_RotateZ->SetValue(0);

	WxSB_ScaleX->SetRange(1, 200); WxSB_ScaleX->SetValue(100);
	WxSB_ScaleY->SetRange(1, 200); WxSB_ScaleY->SetValue(100);
	WxSB_ScaleZ->SetRange(1, 200); WxSB_ScaleZ->SetValue(100);

	//m_button_load_geometry_click(wxCommandEvent());
}

void GUIMyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_button_load_geometry_click(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		double x1, y1, z1, x2, y2, z2;
		int r, g, b;

		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		// std::ifstream in("D:\\Desktop\\a10a_4.geo");
		if (in.is_open())
		{
			data.clear();
			while (!in.eof())
			{
				in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> r >> g >> b;
				data.push_back(Segment(Point(x1, y1, z1), Point(x2, y2, z2), Color(r, g, b)));
			}
			in.close();
		}
	}
}

void GUIMyFrame1::Scrolls_Updated(wxScrollEvent& event)
{
	WxST_TranslationX->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationX->GetValue() - 100) / 50.0));
	WxST_TranslationY->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationY->GetValue() - 100) / 50.0));
	WxST_TranslationZ->SetLabel(wxString::Format(wxT("%g"), (WxSB_TranslationZ->GetValue() - 100) / 50.0));

	WxST_RotateX->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateX->GetValue()));
	WxST_RotateY->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateY->GetValue()));
	WxST_RotateZ->SetLabel(wxString::Format(wxT("%d"), WxSB_RotateZ->GetValue()));

	WxST_ScaleX->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleX->GetValue() / 100.0));
	WxST_ScaleY->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleY->GetValue() / 100.0));
	WxST_ScaleZ->SetLabel(wxString::Format(wxT("%g"), WxSB_ScaleZ->GetValue() / 100.0));


	Repaint();
}


void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(WxPanel);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(wxBrush(RGB(255, 255, 255)));
	dc.Clear();

	double wx = WxPanel->GetSize().x;
	double wy = WxPanel->GetSize().y;

	float translationX = (WxSB_TranslationX->GetValue() - 100.0) / 50.0;
	float translationY = (WxSB_TranslationY->GetValue() - 100.0) / 50.0;
	float translationZ = (WxSB_TranslationZ->GetValue() - 100.0) / 50.0;

	//??
	float angleX = deg_to_rad(static_cast<float>(360.f - WxSB_RotateX->GetValue()));
	float angleY = deg_to_rad(WxSB_RotateY->GetValue());
	float angleZ = deg_to_rad(WxSB_RotateZ->GetValue());

	float scaleX = WxSB_ScaleX->GetValue() / 100.f;
	float scaleY = WxSB_ScaleY->GetValue() / 100.f;
	float scaleZ = WxSB_ScaleZ->GetValue() / 100.f;

	Vector4 vScale;
	Vector4 vTrans;
	Vector4 vRotate;

	vScale.Set(scaleX,scaleY,scaleZ);
	vTrans.Set(translationX,translationY,translationZ+1.1);
	vRotate.Set(angleX,angleY,angleZ);

	//złożenie rotacji itd
	Matrix4 m3D = GetMatrix(vTrans, vRotate, vScale);

	for(const auto & segment : data)
	{
		Vector4 p1;
		p1.Set(segment.begin.x, segment.begin.y, segment.begin.z);
        
		Vector4 p2;
		p2.Set(segment.end.x, segment.end.y, segment.end.z);
		p1 = m3D*p1;
		p2 = m3D*p2;

		dc.SetPen(wxPen(RGB(segment.color.R, segment.color.G, segment.color.B)));

		Matrix4 projMatrix = Projection(90.f,wx/wy,0.1f,100.f);
		auto m1 = projMatrix*p1;
		auto m2 = projMatrix*p2;

		m1.Set(m1.GetX() / m1.GetZ(), m1.GetY() / m1.GetZ(), m1.GetZ() / m1.GetZ());
        m2.Set(m2.GetX() / m2.GetZ(), m2.GetY() / m2.GetZ(), m2.GetZ() / m2.GetZ());
		dc.DrawLine(m1.GetX()+ wx/2, m1.GetY()+ wy/2, m2.GetX()+ wx/2, m2.GetY()+ wy/2);
	}
	
}

double GUIMyFrame1::deg_to_rad(double deg)
{
	return deg*((M_PI)/180.);
}
