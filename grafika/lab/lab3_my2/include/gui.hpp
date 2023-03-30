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
			wxPoint(-90, -110),
			wxPoint(-65, -65),
			wxPoint(-120, -90),
			wxPoint(-60, -90),
			wxPoint(-110, -65)
		};
	public:


		virtual void MainFrameBase_OnPaint(wxPaintEvent& event) override 
		{ 
			wxPaintDC clientDC(this);
			DrawBitmap = wxBitmap(this->GetSize());
			wxBufferedDC buffer(&clientDC, DrawBitmap);

			//setting cords in the middle
			buffer.SetDeviceOrigin(this->GetSize().x / 2 -100, this->GetSize().y / 2-50);
			buffer.SetBackground(*wxWHITE);
			buffer.Clear();


			// TODO
			double bananaFactor = 0.2 * slider_banana->GetValue();

			if (checkbox_banana->IsChecked())
				buffer.DrawBitmap(BananBitmap, -40 - bananaFactor - BananBitmap.GetWidth() / 2, 30 - 0.4 * slider_banana->GetValue() - BananBitmap.GetWidth() / 2, true);
			//head
			buffer.DrawCircle(0, -20, 20);
			//body
			buffer.DrawLine(0, 0, 0, 90); 
			//arm
			buffer.DrawLine(0, 10, -40 - bananaFactor, 30 - 0.4 * slider_banana->GetValue()); 
			buffer.DrawLine(0, 10, 40, 30); 
			buffer.DrawLine(0, 90, -50, 150); 
			buffer.DrawLine(0, 90, 50, 150); 

			//right eye
			buffer.DrawEllipse(4, -31, 6, 9);
			//left eye
			buffer.DrawEllipse(-10, -31, 6, 9);
		
			
			if (checkbox_banana->IsChecked())
			{
				//happy face
				buffer.SetPen(*wxWHITE_PEN);
				buffer.DrawCircle(4, -31, 3);
				buffer.DrawCircle(-10, -31, 3);
				buffer.SetBrush(*wxBLACK_BRUSH);
				buffer.SetPen(*wxBLACK_PEN);
				buffer.DrawCircle(4, -31, 1);
				buffer.DrawCircle(-10, -31, 1);
				
				buffer.DrawEllipticArc(-14, -16, 28, 10, 180, 360);
			} 
			else
			{
				buffer.DrawEllipticArc(-14, -16, 28, 5, 0, 180);
			}

			wxString text(text_box->GetValue());
			buffer.DrawText(text, -90, 90);
			wxString textRotated(text_box->GetValue());
			buffer.SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Kalam"));
			buffer.DrawRotatedText(text_box->GetValue(), 50, 100, 90);

			switch (combo_box->GetSelection())
			{
			case 0:
				buffer.SetBrush(wxBrush(StarColor));
				buffer.SetPen(wxPen(StarColor));
				buffer.DrawPolygon(5, star, 0, 0);
			break;
			case 1:
				buffer.SetBrush(*wxYELLOW_BRUSH);
				buffer.SetPen(*wxYELLOW_PEN);
				buffer.DrawCircle(-90, -120, 20);
			break;
			case 2:
				
				buffer.SetBrush(*wxLIGHT_GREY_BRUSH);
				buffer.SetPen(*wxLIGHT_GREY_PEN);
				buffer.DrawCircle(-90, -90, 20);
				buffer.SetBrush(*wxWHITE_BRUSH);
				buffer.SetPen(*wxWHITE_PEN);
				buffer.DrawCircle(-102, -101, 20);
				buffer.SetBrush(*wxBLACK_BRUSH);
				buffer.SetPen(*wxBLACK_PEN);
				buffer.DrawCircle(-81, -91, 2);
				buffer.DrawLine(-90, -83, -84, -79);
			break;

			default:
			break;
			}
			Refresh(true);
		}

		virtual void MainFrameBase_OnUpdateUI(wxUpdateUIEvent& event) override { } //std::cout << "resize"<< draw_i++<<"\n"; }
		virtual void button_save_CLICK( wxCommandEvent& event ) override 
		{ 
			wxFileDialog saveDialog(this,_("Wybierz plik"), "", "","Image Files (*.png;*.bmp;*.jpg) | ", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
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
			return;
		}
		virtual void checkbox_banana_CLICK( wxCommandEvent& event ) override 
		{ 
			if (!slider_banana->IsEnabled())
                slider_banana->Disable();
            else 
                slider_banana->Enable();
			return;
		}
		virtual void slider_banana_SCROLL( wxScrollEvent& event ) 
		{
			m_gauge2->SetValue(slider_banana->GetValue());
			return;
		}
		virtual void button_star_CLICK(wxCommandEvent& event)
		{
			wxColourDialog chooseColourDialog(this, nullptr);
			if (chooseColourDialog.ShowModal() == wxID_CANCEL)
				return;

			StarColor = chooseColourDialog.GetColourData().GetColour();
		}
		virtual void combo_box_CLICK( wxCommandEvent& event ) override {event.Skip();}
        virtual void file_picker_CLICK( wxFileDirPickerEvent& event ) override {event.Skip();}
		
	public:
		gui() : MyFrame(nullptr)
		{
			BananImage.AddHandler(new wxJPEGHandler);
			BananImage.LoadFile("banana.jpg", wxBITMAP_TYPE_JPEG);
			BananBitmap =  wxBitmap(BananImage);
		}
};