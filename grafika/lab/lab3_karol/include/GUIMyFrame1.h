#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/filefn.h>
#include <wx/dcbuffer.h>
#include <wx/colordlg.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/dcclient.h>
#include <wx/dcgraph.h>
#include <wx/graphics.h>
#include <wx/wfstream.h>

//// end generated include

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void zapis_do_pliku( wxCommandEvent& event );
		void pokaz_banana( wxCommandEvent& event );
		void slider_scrolled( wxScrollEvent& event );
		void zmien_kolor_gwiazdki( wxCommandEvent& event );
		void tekst_zmieniony( wxCommandEvent& event );
		void zmieniono_ksztalt( wxCommandEvent& event );
		virtual void Frame1_OnPaint(wxPaintEvent & event)override{rys();}
		virtual void Frame1_OnUpdateUI(wxUpdateUIEvent & event)override{rys();}

	public:
	wxColor kolor = wxColor(0,0,0);
    wxBitmap bitmap;
    wxBitmap bananbitmap;
    wxPoint gwiazda[5] = {
			wxPoint(-60, -80),
			wxPoint(-35, -35),
			wxPoint(-90, -60),
			wxPoint(-30, -60),
			wxPoint(-80, -35)
	};
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
		 void rys() {
            std::unique_ptr<wxClientDC> clientDC(new wxClientDC(this));
            bitmap = wxBitmap(this->GetSize());
            std::unique_ptr<wxBufferedDC> buffer(new wxBufferedDC(clientDC.get(), bitmap));

            buffer->SetDeviceOrigin(this->GetSize().x / 3, this->GetSize().y / 2);

            buffer->SetBackground(*wxLIGHT_GREY);
            buffer->Clear();

            double bananaFactor = 0.1 * m_gauge1->GetValue() * sin(M_PI * m_gauge1->GetValue() / 100);

            if (Banan->IsChecked())
                buffer->DrawBitmap(bananbitmap, -40 - bananaFactor - bananbitmap.GetWidth() / 2, 30 - 0.4 * m_gauge1->GetValue() - bananbitmap.GetWidth() / 2, true);

            buffer->DrawLine(0, 0, 0, 70); // body
            buffer->DrawLine(0, 10, -40 - bananaFactor, 30 - 0.4 * m_gauge1->GetValue()); //right arm
            buffer->DrawLine(0, 10, 40, 30); // left arm
            buffer->DrawLine(0, 70, -30, 100); // right leg
            buffer->DrawLine(0, 70, 30, 100); // left leg

            buffer->DrawCircle(0, -20, 20);

            buffer->DrawEllipse(-12, -29, 9, 6);
            buffer->DrawEllipse(4, -29, 9, 6);
            if (Banan->IsChecked())
            {
                buffer->DrawEllipticArc(-16, -16, 28, 5, 180, 360);
            } else
            {
                buffer->DrawEllipticArc(-16, -16, 28, 5, 0, 180);
            }
            buffer->SetPen(wxPen(*wxLIGHT_GREY));
            if(Zmiana_ksztaltu->GetSelection()==2) {
                //star
                buffer->SetBrush(wxBrush(kolor));
                buffer->DrawPolygon(5, gwiazda);
            }
            else if(Zmiana_ksztaltu->GetSelection()==0) {
                //moon
                buffer->SetBrush(wxBrush(*wxGREY_BRUSH));
                buffer->DrawCircle(-70, -60, -20);
                buffer->SetBrush(wxBrush(*wxLIGHT_GREY));
                buffer->DrawCircle(-80, -70, -20);
            }
            else if(Zmiana_ksztaltu->GetSelection()==1) {
                //sun
                buffer->SetBrush(wxBrush(*wxYELLOW));
                buffer->DrawCircle(-70, -60, -20);
            }
            wxString text(Pole_tekstowe->GetValue());
            buffer->SetBrush(wxBrush(kolor));

            buffer->DrawText(text, -90, 100);
            wxString textRotated(Pole_tekstowe->GetValue());
            buffer->SetBrush(wxBrush(kolor));
            buffer->SetPen(wxPen(kolor));
            buffer->SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Arial"));
            buffer->DrawRotatedText(Pole_tekstowe->GetValue(), 50, 100, 90);
        }
	//// end generated class members

};

#endif // __GUIMyFrame1__