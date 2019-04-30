///-----------------------------------------------------------------
///
/// @file      UploadFrm.cpp
/// @author    Bugnot, Laboguin, Ramirez
/// Created:   22/10/2018 3:39:41 PM
/// @section   DESCRIPTION
///            UploadFrm class implementation
///
///------------------------------------------------------------------

#include "UploadFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//----------------------------------------------------------------------------
// UploadFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(UploadFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(UploadFrm::OnClose)
	EVT_ACTIVATE(UploadFrm::UploadFrmActivate)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_0,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_9,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_8,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_7,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_6,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_5,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_4,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_3,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_2,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_CONFIDENCE_VALUE_1,UploadFrm::WxEdit1Updated)
	
	EVT_TEXT(ID_PREDICTION_VALUE,UploadFrm::WxEdit1Updated)
	EVT_BUTTON(ID_WXBUTTON2,UploadFrm::WxButton2Click)
	EVT_BUTTON(ID_UPLOAD,UploadFrm::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

UploadFrm::UploadFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

UploadFrm::~UploadFrm()
{
}

void UploadFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	UploadFileDialog =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	confidence_value_0 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_0, _(""), wxPoint(600, 448), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_0"));
	confidence_value_0->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_9 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_9, _(""), wxPoint(600, 418), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_9"));
	confidence_value_9->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_8 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_8, _(""), wxPoint(600, 388), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_8"));
	confidence_value_8->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_7 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_7, _(""), wxPoint(600, 358), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_7"));
	confidence_value_7->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_6 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_6, _(""), wxPoint(600, 328), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_6"));
	confidence_value_6->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	WxStaticText13 = new wxStaticText(this, ID_WXSTATICTEXT13, _("0:"), wxPoint(580, 450), wxDefaultSize, 0, _("WxStaticText13"));
	WxStaticText13->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText12 = new wxStaticText(this, ID_WXSTATICTEXT12, _("9:"), wxPoint(580, 420), wxDefaultSize, 0, _("WxStaticText12"));
	WxStaticText12->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText11 = new wxStaticText(this, ID_WXSTATICTEXT11, _("8:"), wxPoint(580, 390), wxDefaultSize, 0, _("WxStaticText11"));
	WxStaticText11->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText10 = new wxStaticText(this, ID_WXSTATICTEXT10, _("7:"), wxPoint(580, 360), wxDefaultSize, 0, _("WxStaticText10"));
	WxStaticText10->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText9 = new wxStaticText(this, ID_WXSTATICTEXT9, _("6:"), wxPoint(580, 330), wxDefaultSize, 0, _("WxStaticText9"));
	WxStaticText9->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	confidence_value_5 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_5, _(""), wxPoint(450, 448), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_5"));
	confidence_value_5->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_4 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_4, _(""), wxPoint(450, 418), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_4"));
	confidence_value_4->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_3 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_3, _(""), wxPoint(450, 388), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_3"));
	confidence_value_3->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	confidence_value_2 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_2, _(""), wxPoint(450, 358), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_2"));
	confidence_value_2->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	WxStaticText8 = new wxStaticText(this, ID_WXSTATICTEXT8, _("5:"), wxPoint(430, 450), wxDefaultSize, 0, _("WxStaticText8"));
	WxStaticText8->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("4:"), wxPoint(430, 420), wxDefaultSize, 0, _("WxStaticText7"));
	WxStaticText7->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("3:"), wxPoint(430, 390), wxDefaultSize, 0, _("WxStaticText6"));
	WxStaticText6->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("2:"), wxPoint(430, 360), wxDefaultSize, 0, _("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	confidence_value_1 = new wxTextCtrl(this, ID_CONFIDENCE_VALUE_1, _(""), wxPoint(450, 328), wxSize(120, 27), 0, wxDefaultValidator, _("confidence_value_1"));
	confidence_value_1->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("1:"), wxPoint(430, 330), wxDefaultSize, 0, _("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false, _("Siemens AD Sans")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Confidence Level (%)"), wxPoint(487, 292), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxNORMAL, false));

	BmpOutput2 = new wxStaticBitmap(this, ID_BMPOUTPUT2, wxNullBitmap, wxPoint(318, 92), wxSize(20, 20) );

	prediction_value = new wxTextCtrl(this, ID_PREDICTION_VALUE, _(""), wxPoint(586, 105), wxSize(85, 150), 0, wxDefaultValidator, _("prediction_value"));
	prediction_value->SetForegroundColour(wxColour(0,0,0));
	prediction_value->SetFont(wxFont(100, wxSWISS, wxNORMAL, wxBOLD, false));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Prediction:"), wxPoint(411, 161), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(24, wxSWISS, wxNORMAL, wxBOLD, false));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("PREDICT"), wxPoint(40, 430), wxSize(230, 50), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->SetFont(wxFont(22, wxSWISS, wxNORMAL, wxBOLD, false));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Handwriting Image Recognition Using Neural Networks"), wxPoint(36, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(20, wxSWISS, wxNORMAL, wxBOLD, false));

	BmpOutput1 = new wxStaticBitmap(this, ID_BMPOUTPUT1, wxNullBitmap, wxPoint(317, 48), wxSize(20, 20) );

	BmpOutput = new wxStaticBitmap(this, ID_BMPOUTPUT, wxNullBitmap, wxPoint(317, 70), wxSize(20, 20) );

	Upload_Bitmap = new wxStaticBitmap(this, ID_UPLOAD_BITMAP, wxNullBitmap, wxPoint(6, 47), wxSize(300, 300) );
	Upload_Bitmap->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	Upload = new wxButton(this, ID_UPLOAD, _("UPLOAD"), wxPoint(40, 366), wxSize(230, 50), 0, wxDefaultValidator, _("Upload"));
	Upload->SetFont(wxFont(22, wxSWISS, wxNORMAL, wxBOLD, false));

	SetTitle(_("Upload"));
	SetIcon(wxNullIcon);
	SetSize(8,8,808,529);
	Center();
	
	////GUI Items Creation End
}

void UploadFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
//Gaussian Filter Algorithm
wxImage final_gaussian(wxImage my_image)
{
    int image_width = my_image.GetWidth();
    int image_height = my_image.GetHeight();
    unsigned char gaussian_red[image_width][image_height];
    unsigned char gaussian_green[image_width][image_height];
    unsigned char gaussian_blue[image_width][image_height];
    
    for(int y = 0 ; y < image_height; y++){
      
        for(int x = 0; x < image_width; x++){
            
            unsigned char rgb_a = 0;
            unsigned char rgb_b = 0;
            unsigned char rgb_c = 0;
            unsigned char rgb_d = 0;
            unsigned char rgb_e = 0;
            unsigned char rgb_f = 0;
            unsigned char rgb_g = 0;
            unsigned char rgb_h = 0;
            unsigned char rgb_i = 0;
            
            if(x>0 && y<image_height-1){
            //x-1,y+1
            rgb_a = my_image.GetRed(x-1,y+1);
            }
            
            if(y<image_height-1){
            //x,y+1
            rgb_b = my_image.GetRed(x,y+1);
            }
            
            if(x<image_width-1 && y<image_height-1){
            //x+1,y+1
            rgb_c = my_image.GetRed(x+1,y+1);
            }
            
            if(x>0){
            //x-1,y
            rgb_d = my_image.GetRed(x-1,y);
            }
            
            
            //x,y
            rgb_e = my_image.GetRed(x,y);
         
            
            if(x<image_width-1){
            //x+1,y
            rgb_f = my_image.GetRed(x+1,y);
            }
            
            if(x>0 && y>0){
            //x-1,y-1
            rgb_g = my_image.GetRed(x-1,y-1);
            }
            
            if(y>0){   
            //x,y-1
            rgb_h = my_image.GetRed(x,y-1);
            }
            
            if(x<image_width-1 && y>0){
            //x+1,y-1
            rgb_i = my_image.GetRed(x+1,y-1);
            }

            gaussian_red[x][y] = ((rgb_a) + (2*rgb_b)
            + (rgb_c) + (2*rgb_d) + (4*rgb_e) +
            (2*rgb_f) + (rgb_g) + (2*rgb_h) +
            (rgb_i))/16;
            

            
            my_image.SetRGB(x, y, gaussian_red[x][y],
            gaussian_red[x][y], gaussian_red[x][y]);
        }
    }
    
return my_image;
}

//Grayscale Filter Algorithm
wxImage final_grayscale(wxImage img)
{

  for (int i = 0; i < img.GetWidth(); i++)
  {
    for (int j = 0; j < img.GetHeight(); j++)
    {
      unsigned char r = img.GetRed(i,j);
      unsigned char g = img.GetGreen(i,j);
      unsigned char b = img.GetBlue(i,j);
      unsigned char gray = (r*299 + g*587 + b*114)/1000;
      img.SetRGB(i,j,gray,gray,gray); 
    }
  }
                     
  return img;
}

//Invert Algorithm
wxImage final_invert(wxImage images)
{
      for (int i = 0; i < images.GetWidth(); i++)
  {
    for (int j = 0; j < images.GetHeight(); j++)
    {
      unsigned char pre_invert = images.GetRed(i,j);
      
      unsigned char invert = 255 - pre_invert;
      images.SetRGB(i,j,invert,invert,invert); 
      
    }
}

  return images;
}

float UploadFrm::loadData1(string fileloc, const int rows, const int cols)
{
    ifstream file(fileloc.c_str());
    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file >> Theta1[i][j];
                file.get(); // Throw away the comma
            }
        }
    }   
}

float UploadFrm::loadData2(string fileloc, const int rows, const int cols)
{
    ifstream file(fileloc.c_str());
    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file >> Theta2[i][j];
                file.get(); // Throw away the comma
            }
        }
    }
}

void UploadFrm::WxButton1Click(wxCommandEvent& event)
{
UploadFileDialog -> ShowModal();
if (UploadFileDialog -> GetPath().IsEmpty())
{
    return;
}

Upload_Pic.LoadFile(UploadFileDialog -> GetPath(), wxBITMAP_TYPE_ANY);
int h = Upload_Pic.GetHeight();
int w = Upload_Pic.GetWidth();
if (h !=300 && w != 300)
{
    wxImage buff = Upload_Pic;
  
Upload_Bitmap -> SetBitmap(buff.Scale(300,300));
}
else
{
    Upload_Bitmap -> SetBitmap(Upload_Pic);
}
}

void UploadFrm::UploadFrmActivate(wxActivateEvent& event)
{

}

void UploadFrm::WxButton2Click(wxCommandEvent& event)
{
    //Grayscale Click
	  grayscale_filter = final_grayscale(Upload_Pic.Scale(20,20));
    output = grayscale_filter;
    BmpOutput1 -> SetBitmap(output);
    
    //Invert Click
    invert_pic = final_invert(grayscale_filter);
    output = invert_pic;
    BmpOutput2 -> SetBitmap(output);
    
    //Gaussian Click
    gaussian_filter = final_gaussian(invert_pic);
    output = gaussian_filter;
    BmpOutput -> SetBitmap(output);

       for (int i = 0; i < output.GetWidth(); i++)
  {
    for (int j = 0; j < output.GetHeight(); j++)
    {
     int rgb_values=output.GetRed(i,j);
     rgb_array[i][j]=rgb_values;
    }
  }  

 
    for (int i = 0; i < 20; i++)
  {
        for (int j = 0; j < 20; j++)
        {
            unrolledarray[1][i*20+j]= rgb_array[i][j];
        }

    }

	  for(int j = 0; j < 400; ++j)
        {
            mapped[1][j]=((unrolledarray[1][j]/255)*1.30) - 0.15;
        }
            
        for(int i = 400; i>=0; --i)
            {
                input[1][i+1] = mapped[1][i];
            }
            input[1][0] = 1;
            
    UploadFrm::loadData1("Theta1.txt", 25, 401);
	UploadFrm::loadData2("Theta2.txt", 10, 26);
		
        
        //PASS

        for (int j = 0; j < 401; ++j)
        {
            a_1[1][j]=input[1][j];
        }
    
        
    //TRANPOSE
    for(int i = 0; i < 25; ++i)
	{
        for(int j = 0; j < 401; ++j)
        {
            Theta1Trans[j][i]=Theta1[i][j];
        }
    }
	
	//a_1 = 10x401, Theta1Trans = 401x25, a_2 = 10x25
	//MULTIPLY axb * bxc = axc
	for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            a_2[i][j] = 0;
            for (int k = 0; k < 401; k++)
            {
                a_2[i][j] += a_1[i][k] * Theta1Trans[k][j];
            }
        }
    }
	
	//SIGMOID
	for(int i = 0; i < 1; ++i) 
	{
        for(int j = 0; j < 25; j++)
        {
        	a_2[i][j] = 1 / (1 + exp(-1*a_2[i][j]));
        }
    }
    
    //APPEND
    
    for(int i = 0; i < 1; ++i)
	{
        for(int j = 24; j >= 0; --j)
        {
            a_2App[i][j+1]=a_2[i][j];
        }
        a_2App[i][0] = 1;
    }
    
    //TRANPOSE
    for(int i = 0; i < 10; ++i) //Theta2'
	{
        for(int j = 0; j < 26; ++j)
        {
            Theta2Trans[j][i]=Theta2[i][j];
        }
    }
    
       
	
	//MULTIPLY axb * bxc = axc
	//a_2App = 10x26, Theta2Trans = 26x10, a_3 = 10x10;
	for (int i = 0; i < 1; i++) //a_3 = a_2App*Theta2Trans'
    {
        for (int j = 0; j < 10; j++)
        {
            a_3[i][j] = 0;
            for (int k = 0; k < 26; k++)
            {
                a_3[i][j] += a_2App[i][k] * Theta2Trans[k][j];
            }
        }
    }
    
	//SIGMOID
	for(int i = 0; i < 1; ++i) //a_3 = sig(a_3)
	{
        for(int j = 0; j < 10; j++)
        {
        	a_3[i][j] = 1 / (1 + exp(-1*a_3[i][j]));
        }
    }

for(int i = 0; i < 1; ++i) 
	{
        for(int j = 0; j < 10; j++)
        {
        	confidence_a_3[i][j] = a_3[i][j]*100;
        }
    }

    a_3_1 = confidence_a_3[0][0];
    a_3_2 = confidence_a_3[0][1];
    a_3_3 = confidence_a_3[0][2];
    a_3_4 = confidence_a_3[0][3];
    a_3_5 = confidence_a_3[0][4];
    a_3_6 = confidence_a_3[0][5];
    a_3_7 = confidence_a_3[0][6];
    a_3_8 = confidence_a_3[0][7];
    a_3_9 = confidence_a_3[0][8];
    a_3_0 = confidence_a_3[0][9];
    
   
	//MAX
	
	for(int i = 0; i < 1; ++i)
	{
        for(int j = 0; j < 10; j++)
        {
        	conf[i] = max(conf[i],a_3[i][j]);
        }
    }
    //MAX INDEX
     for (int i = 0; i < 1; i++)
    {
       uncalib_pred = distance(a_3[i], max_element(a_3[i], a_3[i] + 10));
       
       if (uncalib_pred < 9)
       {
       		calib_pred = uncalib_pred + 1;
	   }
	   else
	   {
	   		calib_pred = 0;
	   }
       
    }
            	
prediction_value->SetValue(wxString::Format(wxT("%i"), calib_pred));
confidence_value_1->SetValue(wxString::Format(wxT("%1f"), a_3_1));
confidence_value_2->SetValue(wxString::Format(wxT("%1f"), a_3_2));
confidence_value_3->SetValue(wxString::Format(wxT("%1f"), a_3_3));
confidence_value_4->SetValue(wxString::Format(wxT("%1f"), a_3_4));
confidence_value_5->SetValue(wxString::Format(wxT("%1f"), a_3_5));
confidence_value_6->SetValue(wxString::Format(wxT("%1f"), a_3_6));
confidence_value_7->SetValue(wxString::Format(wxT("%1f"), a_3_7));
confidence_value_8->SetValue(wxString::Format(wxT("%1f"), a_3_8));
confidence_value_9->SetValue(wxString::Format(wxT("%1f"), a_3_9));
confidence_value_0->SetValue(wxString::Format(wxT("%1f"), a_3_0));
}


void UploadFrm::WxEdit1Updated(wxCommandEvent& event)
{
	
}
