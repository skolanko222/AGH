#include <wx/wxprec.h>
// g++ main.cpp -o main `wx-config --cppflags`

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	void Mouse_Move(wxMouseEvent& e);
	void Form_Paint(wxPaintEvent& e);
	bool DrawFlag;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	//SetProcessDPIAware();
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 05")
{
	SetTitle(wxString::FromUTF8("Demo 05 - Funkcje rysujące"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 699, 526);
	Center();

	Bind(wxEVT_MOTION, &MyFrame::Mouse_Move, this);
	Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);
	this->Bind(wxEVT_LEFT_DOWN, [&, this](wxMouseEvent& e) { DrawFlag = true; });
	this->Bind(wxEVT_LEFT_UP, [&, this](wxMouseEvent& e) { DrawFlag = false; });
	DrawFlag = false;
}

void MyFrame::Mouse_Move(wxMouseEvent& e)
{
	int x, y;
	if (DrawFlag)
	{
		wxClientDC MyDC(this);
		x = e.GetX();
		y = e.GetY();
		MyDC.SetPen(wxPen(*wxBLACK, 1));
		MyDC.DrawPoint(x, y);
	}
}

void MyFrame::Form_Paint(wxPaintEvent& event)
{
	int i, j;
	wxPoint pts[5] = 
	{ 
		wxPoint(200, 40), wxPoint(220, 60), wxPoint(240, 50), 
		wxPoint(260, 60), wxPoint(280, 40)
	};
	wxPoint ptsB[4] = 
	{ 
		wxPoint(400, 90), wxPoint(415, 240), 
		wxPoint(480, 90), wxPoint(520, 140) 
	};
	wxPen MyPen;

	wxPaintDC* MyDC;
	MyDC = new wxPaintDC(this);
	MyDC->SetPen(wxPen(*wxBLACK, 1));

	MyDC->DrawArc(75, 180, 155, 220, 75, 200);
	MyDC->DrawCheckMark(0, 160, 40, 40);
	MyDC->DrawCircle(50, 260, 40);
	MyDC->DrawEllipse(25, 300, 100, 60);
	MyDC->DrawEllipticArc(25, 360, 100, 60, 130, 290);

	MyDC->DrawLine(160, 10, 300, 30);
	MyDC->DrawLines(5, pts);

	MyDC->DrawPolygon(5, pts, -30, 50);

	MyDC->DrawRectangle(170, 120, 120, 60);
	MyDC->DrawRoundedRectangle(170, 190, 100, 35, 12);
	MyDC->DrawSpline(4, ptsB);

	MyDC->DrawText("QWERTY 123 zxcvb", 400, 30);
	MyDC->DrawRotatedText("QWERTY 123 zxcvb", 400, 250, 30);


	for (i = 0; i < 150; i++)
		for (j = 0; j < 150; j++)
		{
			MyPen.SetColour(i, 2*i - j, j);
			MyDC->SetPen(MyPen);
			MyDC->DrawPoint(i, j);
		}

	delete (MyDC);
}