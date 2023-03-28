#include <memory>
#include "MyFrame.hpp"
#pragma once
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

class gui : public MyFrame
{
	private:
		wxBitmap DrawBitmap;

		wxBitmap BananBitmap;
 		wxImage  BananImage;
		int resize = 0;
		int draw_i = 0;

		

		wxColor StarColor = wxColor(122,0,0);
	
		wxPoint star[5] = {
			wxPoint(-60, -80),
			wxPoint(-35, -35),
			wxPoint(-90, -60),
			wxPoint(-30, -60),
			wxPoint(-80, -35)
		};
	protected:
		void Draw(wxPaintDC &a)
		{
			
			std::unique_ptr<wxPaintDC> clientDC(new wxWindowDC(this));
			DrawBitmap = wxBitmap(this->GetSize());
			std::unique_ptr<wxBufferedDC> buffer(new wxBufferedDC(clientDC.get(), DrawBitmap));

			//ustawiamy uklad wspolrzednych na srodku
			buffer->SetDeviceOrigin(this->GetSize().x / 2, this->GetSize().y / 2);
			buffer->SetBackground(*wxLIGHT_GREY);
			buffer->Clear();


			// TODO
			double bananaFactor = 0.1 * slider_banana->GetValue() * sin(M_PI * slider_banana->GetValue() / 100);

			if (checkbox_banana->IsChecked())
				buffer->DrawBitmap(BananBitmap, -40 - bananaFactor - BananBitmap.GetWidth() / 2, 30 - 0.4 * slider_banana->GetValue() - BananBitmap.GetWidth() / 2, true);

			buffer->DrawLine(0, 0, 0, 70); // body
			buffer->DrawLine(0, 10, -40 - bananaFactor, 30 - 0.4 * slider_banana->GetValue()); //right arm
			buffer->DrawLine(0, 10, 40, 30); // left arm
			buffer->DrawLine(0, 70, -30, 100); // right leg
			buffer->DrawLine(0, 70, 30, 100); // left leg

			buffer->DrawCircle(0, -20, 20);

			buffer->DrawEllipse(-12, -29, 9, 6);
			if (checkbox_banana->IsChecked())
			{
				buffer->DrawEllipticArc(-14, -16, 28, 5, 180, 360);
				buffer->DrawEllipse(3, -29, 9, 6);
			} 
			else
			{
				buffer->DrawEllipticArc(-14, -16, 28, 5, 0, 180);
				buffer->DrawEllipse(4, -31, 6, 9);
			}

			wxString text(text_box->GetValue());
			buffer->DrawText(text, -90, 90);
			wxString textRotated(text_box->GetValue());
			buffer->SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Kalam"));
			buffer->DrawRotatedText(text_box->GetValue(), 50, 100, 90);

			switch (combo_box->GetSelection())
			{
			case 0:
			buffer->SetBrush(wxBrush(StarColor));
			buffer->SetPen(wxPen(StarColor));
			buffer->DrawPolygon(5, star, 0, 0);
			break;

			case 1:
			buffer->SetBrush(*wxLIGHT_GREY_BRUSH);
			buffer->SetPen(*wxLIGHT_GREY_PEN);
			buffer->DrawCircle(-70, -70, 20);
			buffer->SetBrush(*wxWHITE_BRUSH);
			buffer->SetPen(*wxWHITE_PEN);
			buffer->DrawCircle(-80, -80, 20);
			buffer->SetBrush(*wxBLACK_BRUSH);
			buffer->SetPen(*wxBLACK_PEN);
			buffer->DrawCircle(-60, -70, 2);
			buffer->DrawLine(-70, -63, -64, -59);
			break;

			case 2:
			buffer->SetBrush(*wxYELLOW_BRUSH);
			buffer->SetPen(*wxYELLOW_PEN);
			buffer->DrawCircle(-70, -70, 20);
			break;

			default:
			break;
			}
		}

		virtual void MainFrameBase_OnPaint(wxPaintEvent& event) override 
		{ 
			wxPaintDC dc(this);
			Draw(dc); 
			std::cout << "rysuj " << resize++ <<  '\n'; 
		}

		virtual void MainFrameBase_OnUpdateUI(wxUpdateUIEvent& event) override { std::cout << "resize"<< draw_i++<<"\n";}
		
		virtual void button_save_CLICK( wxCommandEvent& event ) override 
		{ 
			wxFileDialog saveDialog(this,_("Wybierz plik"), "", "","Image Files (*.png;*.bmp;*.jpg)", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
			wxImage _imageSave = DrawBitmap.ConvertToImage();
			if (saveDialog.ShowModal() == wxID_CANCEL)
				return;
			else
			{
				_imageSave.AddHandler(new wxBMPHandler);
				_imageSave.AddHandler(new wxPNGHandler);
				_imageSave.SaveFile(saveDialog.GetPath());
			}
			//Draw();
		}
		virtual void checkbox_banana_CLICK( wxCommandEvent& event ) override { }
		virtual void checkBox_banana_Check(wxCommandEvent& event)
		{
			std::cout << "banan klikniety\n";
			slider_banana->Enable(checkbox_banana->IsChecked());
			//Draw();
		}
		virtual void slider_banana_pos_OnScroll(wxScrollEvent& event)
		{
			m_gauge2->SetValue(event.GetPosition());
			//Draw();
		}
		virtual void button_star_CLICK(wxCommandEvent& event)
		{
			wxColourDialog chooseColourDialog(this, nullptr);
			if (chooseColourDialog.ShowModal() == wxID_CANCEL)
				return;

			StarColor = chooseColourDialog.GetColourData().GetColour();
			//Draw();
		}
		
	public:
		gui() : MyFrame(NULL)
		{
			BananImage.AddHandler(new wxJPEGHandler);
			BananImage.LoadFile("banan.jpeg", wxBITMAP_TYPE_JPEG);
			BananBitmap =  wxBitmap(BananImage);
		}



};