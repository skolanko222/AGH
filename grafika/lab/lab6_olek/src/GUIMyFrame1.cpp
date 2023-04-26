#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
 m_staticText1->SetLabel(_(L"Jasnosc"));
 m_b_threshold->SetLabel(_(L"Prog 128"));
 this->SetBackgroundColour(wxColor(192, 192, 192));
 m_scrolledWindow->SetScrollbars(25, 25, 52, 40);
 m_scrolledWindow->SetBackgroundColour(wxColor(192, 192, 192));
}

void GUIMyFrame1::m_scrolledWindow_update( wxUpdateUIEvent& event )
{
 Repaint();
}

void GUIMyFrame1::m_b_grayscale_click( wxCommandEvent& event )
{
 // TO DO: Konwersja do skali szarosci 
    Img_Cpy=Img_Org.ConvertToGreyscale();
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_blur_click( wxCommandEvent& event )
{
 // TO DO: Rozmywanie obrazu (blur)
 Img_Cpy = Img_Org.Blur(5);
 m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_mirror_click( wxCommandEvent& event )
{
 // TO DO: Odbicie lustrzane
    Img_Cpy = Img_Org.Mirror();
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_replace_click( wxCommandEvent& event )
{
 // TO DO: Zamiana kolorow 
    Img_Cpy=Img_Org.Copy();
    unsigned char* data = Img_Cpy.GetData();
    int width = Img_Cpy.GetWidth();
    int height = Img_Cpy.GetHeight();

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(data[3*(i*width+j)]>220)
            {
                data[3*(i*width+j)+2]=255;
                data[3*(i*width+j)+1]=0;
                data[3*(i*width+j)]=0;
            }
        }
    }
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_rescale_click( wxCommandEvent& event )
{
 // TO DO: Zmiana rozmiarow do 320x240
    Img_Cpy=Img_Org.Copy();
    Img_Cpy.Rescale(320, 240);
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_rotate_click( wxCommandEvent& event )
{
 // TO DO: Obrot o 30 stopni
    Img_Cpy=Img_Org.Rotate(30*M_PI/180, wxPoint(Img_Org.GetWidth()/2, Img_Org.GetHeight()/2), true, NULL);
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_rotate_hue_click( wxCommandEvent& event )
{
 // TO DO: Przesuniecie Hue o 180 stopni
    Img_Cpy=Img_Org.Copy();
    Img_Cpy.RotateHue(180.0/360.0);
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_mask_click( wxCommandEvent& event )
{
 // TO DO: Ustawienie maski obrazu
    Img_Cpy=Img_Org.Copy();
    Img_Cpy.SetMaskFromImage(Img_Mask, 0, 0, 0);
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_s_brightness_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Brightness(...), ktora zmienia jasnosc. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Brightness(...)
Brightness(m_s_brightness->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_s_contrast_scroll( wxScrollEvent& event )
{
// Tutaj, w reakcji na zmiane polozenia suwaka, wywolywana jest funkcja
// Contrast(...), ktora zmienia kontrast. W tym miejscu nic nie
// zmieniamy. Do uzupelnienia pozostaje funkcja Contrast(...)
Contrast(m_s_contrast->GetValue() - 100);
Repaint();
}

void GUIMyFrame1::m_b_prewitt_click( wxCommandEvent& event )
{
 // TO DO: Pionowa maska Prewitta
    Img_Cpy = Img_Org.ConvertToGreyscale();
    wxImage tmp = Img_Cpy.Copy();
    unsigned char* data = Img_Cpy.GetData();
    int width = Img_Cpy.GetWidth();
    int height = Img_Cpy.GetHeight();

    for(int i=1; i<height-1; i++)
    {
        for(int j=1; j<width-1; j++)
        {
            int x = Img_Cpy.GetRed(j-1,i-1)+Img_Cpy.GetRed(j,i-1)+Img_Cpy.GetRed(j+1,i-1)-Img_Cpy.GetRed(j-1,i+1)-Img_Cpy.GetRed(j,i+1)-Img_Cpy.GetRed(j+1,i+1);
            int y = Img_Cpy.GetRed(j-1,i-1)+Img_Cpy.GetRed(j,i-1)+Img_Cpy.GetRed(j+1,i-1)-Img_Cpy.GetRed(j-1,i+1)-Img_Cpy.GetRed(j,i+1)-Img_Cpy.GetRed(j+1,i+1);
            int value = sqrt(x*x + y*y);
            if(value>255) value=255;
            if(value<0) value=0;
            tmp.SetRGB(j, i, value, value, value);
        }
    }
    Img_Cpy = tmp;
    m_scrolledWindow->ClearBackground();
}

void GUIMyFrame1::m_b_threshold_click( wxCommandEvent& event )
{
 // TO DO: Prog o wartosci 128 dla kazdego kanalu niezaleznie
    Img_Cpy=Img_Org.Copy();
    unsigned char* data = Img_Cpy.GetData();
    int size = Img_Cpy.GetWidth()*Img_Cpy.GetHeight()*3;

    for(int i=0; i<size; i++)
    {
        if(data[i]<128) data[i]=0;
        else data[i]=255;
    }
    m_scrolledWindow->ClearBackground();
}


void GUIMyFrame1::Contrast(int value)
{
 // TO DO: Zmiana kontrastu obrazu. value moze przyjmowac wartosci od -100 do 100
    Img_Cpy = Img_Org.Copy();
    unsigned char* data = Img_Cpy.GetData();
    int size = Img_Cpy.GetWidth()*Img_Cpy.GetHeight()*3;
    double value1 = value*255/100;
    value1 = (259*(value1+255))/(255*(259-value1));
    for(int i=0; i<size; i++)
    {
        int tmp = value1*(data[i]-128)+128;
        if(tmp<0) tmp=0;
        else if(tmp>255) tmp=255;
        data[i] = tmp;
    }
}

void GUIMyFrame1::Repaint()
{
//clear the window and draw the image
 wxBitmap bitmap(Img_Cpy);          // Tworzymy tymczasowa bitmape na podstawie Img_Cpy
 wxClientDC dc(m_scrolledWindow);   // Pobieramy kontekst okna
 m_scrolledWindow->DoPrepareDC(dc); // Musimy wywolac w przypadku wxScrolledWindow, zeby suwaki prawidlowo dzialaly
 dc.DrawBitmap(bitmap, 0, 0, true); // Rysujemy bitmape na kontekscie urzadzenia
}

void GUIMyFrame1::Brightness(int value)
{
 // TO DO: Zmiana jasnosci obrazu. value moze przyjmowac wartosci od -100 do 100
    Img_Cpy = Img_Org.Copy();
    unsigned char* data = Img_Cpy.GetData();
    int size = Img_Cpy.GetWidth()*Img_Cpy.GetHeight()*3;

    for(int i=0; i<size; i++)
    {
        if(data[i]+value<0) data[i]=0;
        else if(data[i]+value>255) data[i]=255;
        else data[i]+=value;
    }
}