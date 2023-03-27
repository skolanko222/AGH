#include "Frame.h"
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

class Picture : public Frame1
{
    wxColor kolor=wxColor(0,0,0);
    wxBitmap bitmap;
    wxBitmap bananbitmap;
    wxPoint gwiazda[5] = {
			wxPoint(-60, -80),
			wxPoint(-35, -35),
			wxPoint(-90, -60),
			wxPoint(-30, -60),
			wxPoint(-80, -35)
	};
    void rys() {
            std::unique_ptr<wxClientDC> clientDC(new wxClientDC(this));
            bitmap = wxBitmap(this->GetSize());
            std::unique_ptr<wxBufferedDC> buffer(new wxBufferedDC(clientDC.get(), bitmap));

            buffer->SetDeviceOrigin(this->GetSize().x / 3, this->GetSize().y / 2);

            buffer->SetBackground(*wxLIGHT_GREY);
            buffer->Clear();

            double bananaFactor = 0.1 * gauge_banan->GetValue() * sin(M_PI * gauge_banan->GetValue() / 100);

            if (checkbox_banan->IsChecked())
                buffer->DrawBitmap(bananbitmap, -40 - bananaFactor - bananbitmap.GetWidth() / 2, 30 - 0.4 * gauge_banan->GetValue() - bananbitmap.GetWidth() / 2, true);

            buffer->DrawLine(0, 0, 0, 70); // body
            buffer->DrawLine(0, 10, -40 - bananaFactor, 30 - 0.4 * gauge_banan->GetValue()); //right arm
            buffer->DrawLine(0, 10, 40, 30); // left arm
            buffer->DrawLine(0, 70, -30, 100); // right leg
            buffer->DrawLine(0, 70, 30, 100); // left leg

            buffer->DrawCircle(0, -20, 20);

            buffer->DrawEllipse(-12, -29, 9, 6);
            buffer->DrawEllipse(4, -29, 9, 6);
            if (checkbox_banan->IsChecked())
            {
                buffer->DrawEllipticArc(-16, -16, 28, 5, 180, 360);
            } else
            {
                buffer->DrawEllipticArc(-16, -16, 28, 5, 0, 180);
            }
            buffer->SetPen(wxPen(*wxLIGHT_GREY));
            if(comboBox_star->GetSelection()==2) {
                //star
                buffer->SetBrush(wxBrush(kolor));
                buffer->DrawPolygon(5, gwiazda);
            }
            else if(comboBox_star->GetSelection()==0) {
                //moon
                buffer->SetBrush(wxBrush(*wxGREY_BRUSH));
                buffer->DrawCircle(-70, -60, -20);
                buffer->SetBrush(wxBrush(*wxLIGHT_GREY));
                buffer->DrawCircle(-80, -70, -20);
            }
            else if(comboBox_star->GetSelection()==1) {
                //sun
                buffer->SetBrush(wxBrush(*wxYELLOW));
                buffer->DrawCircle(-70, -60, -20);
            }
            wxString text(tekst->GetValue());
            buffer->SetBrush(wxBrush(kolor));

            buffer->DrawText(text, -90, 100);
            wxString textRotated(tekst->GetValue());
            buffer->SetBrush(wxBrush(kolor));
            buffer->SetPen(wxPen(kolor));
            buffer->SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Arial"));
            buffer->DrawRotatedText(tekst->GetValue(), 50, 100, 90);
        }
    protected:
        virtual void Frame1_OnPaint( wxPaintEvent& event ) override{rys();}   
        virtual void Frame1_OnUpdateUI( wxUpdateUIEvent& event ) override{rys();}//rys();}
        virtual void OnClickSave(wxCommandEvent& event) override{
            wxFileDialog saveFileDialog(this, _("Zapisz obraz"), "", "","Pliki JPEG (*.jpg)|*.jpg", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
            if (saveFileDialog.ShowModal() == wxID_CANCEL)
                return;
            wxFileOutputStream output_stream(saveFileDialog.GetPath());
        }
        virtual void OnClickCheckBanana(wxCommandEvent& event) override{
            if (slider_banan->IsEnabled()) {
                slider_banan->Disable();
                slider_banan->SetValue(50);
            }
            else {
                slider_banan->Enable();
                slider_banan->SetValue(0);
                gauge_banan->SetValue(0);
            }
            rys();
        }
        virtual void Onscroll_banan(wxScrollEvent& event) override{
            gauge_banan->SetValue(slider_banan->GetValue());
            rys();
        }
        virtual void OnClickColor(wxCommandEvent& event) override{
            wxColourDialog dialog(this);
            if (dialog.ShowModal() == wxID_OK) {
                kolor = dialog.GetColourData().GetColour();
                tekst->SetForegroundColour(kolor);
            }
            rys();
        }
        virtual void comboBox_star_OnCombobox( wxCommandEvent& event ) override{event.Skip();}
        virtual void OnFilePicker( wxFileDirPickerEvent& event ) override{event.Skip();}
    public:
        Picture() : Frame1(NULL) {
            wxImage image;
            wxInitAllImageHandlers();
            image.LoadFile("banant.jpeg");
            image.Rescale(50,50);
            bananbitmap = wxBitmap(image);
            if (bananbitmap.IsOk()) {
                std::cout << "bananbitmap is ok" << std::endl;
            }
        }
        ~Picture() {
        }

};