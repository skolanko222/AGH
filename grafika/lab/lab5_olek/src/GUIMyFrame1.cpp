#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>
#include "vecmat.h"

struct Point {
 float x, y, z;
 Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct Color {
 int R, G, B;
 Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};

struct Segment {
 Point begin, end;
 Color color;
 Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
};

std::vector<Segment> data;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
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
}

void GUIMyFrame1::WxPanel_Repaint( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_button_load_geometry_click( wxCommandEvent& event )
{
 wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

 if (WxOpenFileDialog.ShowModal() == wxID_OK)
 {
  double x1, y1, z1, x2, y2, z2;
  int r, g, b;

  std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
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

void GUIMyFrame1::Scrolls_Updated( wxScrollEvent& event )
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
    angle = angle * M_PI / 180;
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
    angle = angle * M_PI / 180;
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
    angle = angle * M_PI / 180;
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

void GUIMyFrame1::Repaint() {

    wxClientDC dc(WxPanel);
    wxBufferedDC bdc(&dc);

    bdc.SetBackground(wxBrush(*wxWHITE));
    bdc.Clear();

    double sizex = WxPanel->GetSize().x;
    double sizey = WxPanel->GetSize().y;

    double scalex = WxSB_ScaleX->GetValue() / 100.0;
    double scaley = WxSB_ScaleY->GetValue() / 100.0;
    double scalez = WxSB_ScaleZ->GetValue() / 100.0;

    double transx = (WxSB_TranslationX->GetValue() - 100) / 50.0;
    double transy = (WxSB_TranslationY->GetValue() - 100) / 50.0;
    double transz = (WxSB_TranslationZ->GetValue() - 100) / 50.0;

    double rotx = WxSB_RotateX->GetValue();
    double roty = WxSB_RotateY->GetValue();
    double rotz = WxSB_RotateZ->GetValue();

    Vector4 Scalev,Translationv,Rotationv;

    Scalev.Set(scalex, scaley, scalez);
    Translationv.Set(-transx, transy, transz+1.1);
    Rotationv.Set(rotx, roty, rotz);

    Matrix4 m = GetMatrix(Translationv, Rotationv, Scalev);

    for(const auto& segment : data) {
        Vector4 p1;
        Vector4 p2;

        p1.Set(segment.begin.x, segment.begin.y, segment.begin.z);
        p2.Set(segment.end.x, segment.end.y, segment.end.z);

        bdc.SetPen(wxPen(RGB(segment.color.R, segment.color.G, segment.color.B)));

        auto m2 = m*p1;
        auto m3 = m*p2;

        auto clipvalue=0.1f;
        // if((m2.GetZ() > clipvalue && m3.GetZ() <= clipvalue) || (m2.GetZ() <= clipvalue && m3.GetZ() > clipvalue)) {
        //     Vector4 p3 = m3.GetZ() <= clipvalue ? p1 : p2;
        //     Vector4 p4 = m3.GetZ() <= clipvalue ? p2 : p1;
        //     double t = abs((clipvalue - p3.GetZ()) / (p4.GetZ() - p3.GetZ()));
        //     p4.Set(p3.GetX() + t * (p4.GetX() - p3.GetX()), p3.GetY() + t * (p4.GetY() - p3.GetY()),clipvalue);
        //     m2 = p3;
        //     m3 = p4;
        // }
        // else if (m2.GetZ() <= clipvalue && m3.GetZ() <= clipvalue){
        //     continue;
        // }

        //projekcja obiektu 3d na płaszczyzne 2d
        Matrix4 m4 = Projection(90.f,sizex/sizey,0.1f,100.f);

        m2 = m4 * m2;
        m3 = m4 * m3;

        // m2.Set(m2.GetX() / m2.GetZ(), m2.GetY() / m2.GetZ(), m2.GetZ() / m2.GetZ());
        // m3.Set(m3.GetX() / m3.GetZ(), m3.GetY() / m3.GetZ(), m3.GetZ() / m3.GetZ());

        bdc.DrawLine(m2.GetX()+sizex/2.0f, m2.GetY()+sizey/2.0f, m3.GetX()+sizex/2.0f, m3.GetY()+sizey/2.0f);
    }
}