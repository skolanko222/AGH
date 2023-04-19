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
	m = Scale(m, scale.GetX(), scale.GetY(), scale.GetZ());
	m = Translate(m, translation.GetX(), translation.GetY(), translation.GetZ());
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
	// 1 //
	Matrix4 m1;
	m1.data[0][0] = WxSB_ScaleX->GetValue() / 100.0;
	m1.data[1][1] = WxSB_ScaleY->GetValue() / 100.0;
	m1.data[2][2] = WxSB_ScaleZ->GetValue() / 100.0;

	Matrix4 m2;
	double alpha = WxSB_RotateZ->GetValue() * M_PI / 180.0;
	m2.data[0][0] = cos(alpha);
	m2.data[0][1] = sin(alpha);
	m2.data[1][0] = -sin(alpha);
	m2.data[1][1] = cos(alpha);
	m2.data[2][2] = 1;

	Matrix4 m3;
	alpha = WxSB_RotateY->GetValue() * M_PI / 180.0;
	m3.data[0][0] = cos(alpha);
	m3.data[0][2] = -sin(alpha);
	m3.data[1][1] = 1;
	m3.data[2][0] = sin(alpha);
	m3.data[2][2] = cos(alpha);

	Matrix4 m4;
	alpha = WxSB_RotateX->GetValue() * M_PI / 180.0;
	m4.data[0][0] = 1;
	m4.data[1][1] = cos(alpha);
	m4.data[1][2] = sin(alpha);
	m4.data[2][1] = -sin(alpha);
	m4.data[2][2] = cos(alpha);

	Matrix4 m5;
	m5.data[0][0] = 1;
	m5.data[0][3] = (WxSB_TranslationX->GetValue() - 100.0) / 50.0;
	m5.data[1][1] = 1;
	m5.data[1][3] = (WxSB_TranslationY->GetValue() - 100.0) / 50.0;
	m5.data[2][2] = 1;
	m5.data[2][3] = (WxSB_TranslationZ->GetValue() - 100.0) / 50.0;

	Matrix4 transform1 = m5 * m4 * m3 * m2 * m1;

	// 2 //
	Matrix4 m6;
	m6.data[0][0] = 1;
	m6.data[1][1] = 1;
	m6.data[3][2] = 1.0 / 2.0;

	Matrix4 m7;
	m7.data[0][0] = WxPanel->GetSize().GetWidth() / 2;
	m7.data[1][1] = -WxPanel->GetSize().GetHeight() / 2;
	m7.data[0][3] = WxPanel->GetSize().GetWidth() / 2;
	m7.data[1][3] = WxPanel->GetSize().GetHeight() / 2;

	Matrix4 transform2 = m7 * m6;

	// a //
	wxClientDC _dc(WxPanel);
	wxBufferedDC dc(&_dc);

	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();

	// b //
	for (Segment segment : data) {
		dc.SetPen(wxPen(wxColour(segment.color.R, segment.color.G, segment.color.B)));

		Vector4 startPoint, endPoint;
		startPoint.Set(segment.begin.x, segment.begin.y, segment.begin.z);
		endPoint.Set(segment.end.x, segment.end.y, segment.end.z);

		startPoint = transform1 * startPoint;
		endPoint = transform1 * endPoint;

		startPoint.data[0] /= startPoint.data[3];
		startPoint.data[1] /= startPoint.data[3];
		startPoint.data[2] /= startPoint.data[3];

		endPoint.data[0] /= endPoint.data[3];
		endPoint.data[1] /= endPoint.data[3];
		endPoint.data[2] /= endPoint.data[3];

		if ( (startPoint.GetZ() > -2.0 && endPoint.GetZ() <= -2.0) || (endPoint.GetZ() > -2.0 && startPoint.GetZ() <= -2.0) ) {
			Vector4 temp1 = endPoint.GetZ() <= -2.0 ? endPoint : startPoint;
			Vector4 temp2 = endPoint.GetZ() <= -2.0 ? startPoint : endPoint;
			double r = abs((-2.0 - temp1.data[2]) / (temp2.data[2] - temp1.data[2]));
			temp1.data[0] = (temp2.data[0] - temp1.data[0]) * r + temp1.data[0];
			temp1.data[1] = (temp2.data[1] - temp1.data[1]) * r + temp1.data[1];
			temp1.data[2] = -2.0;

			startPoint = transform2 * temp1;
			endPoint = transform2 * temp2;

			startPoint.data[0] /= startPoint.data[3];
			startPoint.data[1] /= startPoint.data[3];
			startPoint.data[2] /= startPoint.data[3];

			endPoint.data[0] /= endPoint.data[3];
			endPoint.data[1] /= endPoint.data[3];
			endPoint.data[2] /= endPoint.data[3];
		}
		else if (startPoint.GetZ() <= -2.0 && endPoint.GetZ() <= -2.0) {
			continue;
		}
		else {
			startPoint = transform2 * startPoint;
			endPoint = transform2 * endPoint;

			startPoint.data[0] /= startPoint.data[3];
			startPoint.data[1] /= startPoint.data[3];
			startPoint.data[2] /= startPoint.data[3];

			endPoint.data[0] /= endPoint.data[3];
			endPoint.data[1] /= endPoint.data[3];
			endPoint.data[2] /= endPoint.data[3];
		}

		dc.DrawLine(startPoint.GetX(), startPoint.GetY(), endPoint.GetX(), endPoint.GetY());
}
}

double GUIMyFrame1::deg_to_rad(double deg)
{
	return deg*((M_PI)/180.);
}
