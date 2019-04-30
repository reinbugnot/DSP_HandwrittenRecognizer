///-----------------------------------------------------------------
///
/// @file      UploadFrm.h
/// @author    user
/// Created:   22/10/2018 3:39:40 PM
/// @section   DESCRIPTION
///            UploadFrm class declaration
///
///------------------------------------------------------------------

#ifndef __UPLOADFRM_H__
#define __UPLOADFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/button.h>
////Header Include End
#include <iostream>
#include <fstream>
#include <string>
////Dialog Style Start
#undef UploadFrm_STYLE
#define UploadFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class UploadFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		UploadFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Upload"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = UploadFrm_STYLE);
		virtual ~UploadFrm();
		void WxButton1Click(wxCommandEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void GrayscaleClick(wxCommandEvent& event);
		void UploadFrmActivate(wxActivateEvent& event);
		void InvertClick(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void read_handwriting();
		float loadData1(std::string fileloc, const int rows, const int cols);
        float loadData2(std::string fileloc, const int rows, const int cols);	
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *UploadFileDialog;
		wxTextCtrl *confidence_value_0;
		wxTextCtrl *confidence_value_9;
		wxTextCtrl *confidence_value_8;
		wxTextCtrl *confidence_value_7;
		wxTextCtrl *confidence_value_6;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxTextCtrl *confidence_value_5;
		wxTextCtrl *confidence_value_4;
		wxTextCtrl *confidence_value_3;
		wxTextCtrl *confidence_value_2;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxTextCtrl *confidence_value_1;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticBitmap *BmpOutput2;
		wxTextCtrl *prediction_value;
		wxStaticText *WxStaticText2;
		wxButton *WxButton2;
		wxStaticText *WxStaticText1;
		wxStaticBitmap *BmpOutput1;
		wxStaticBitmap *BmpOutput;
		wxStaticBitmap *Upload_Bitmap;
		wxButton *Upload;
		////GUI Control Declaration End
		wxImage Upload_Pic;
		wxImage gaussian_filter;
		wxImage grayscale_filter;
		wxImage invert_pic;
		wxImage output;
	
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_CONFIDENCE_VALUE_0 = 1039,
			ID_CONFIDENCE_VALUE_9 = 1038,
			ID_CONFIDENCE_VALUE_8 = 1037,
			ID_CONFIDENCE_VALUE_7 = 1036,
			ID_CONFIDENCE_VALUE_6 = 1035,
			ID_WXSTATICTEXT13 = 1034,
			ID_WXSTATICTEXT12 = 1033,
			ID_WXSTATICTEXT11 = 1032,
			ID_WXSTATICTEXT10 = 1031,
			ID_WXSTATICTEXT9 = 1030,
			ID_CONFIDENCE_VALUE_5 = 1029,
			ID_CONFIDENCE_VALUE_4 = 1028,
			ID_CONFIDENCE_VALUE_3 = 1027,
			ID_CONFIDENCE_VALUE_2 = 1026,
			ID_WXSTATICTEXT8 = 1025,
			ID_WXSTATICTEXT7 = 1024,
			ID_WXSTATICTEXT6 = 1023,
			ID_WXSTATICTEXT5 = 1022,
			ID_CONFIDENCE_VALUE_1 = 1021,
			ID_WXSTATICTEXT4 = 1020,
			ID_WXSTATICTEXT3 = 1019,
			ID_BMPOUTPUT2 = 1017,
			ID_PREDICTION_VALUE = 1014,
			ID_WXSTATICTEXT2 = 1011,
			ID_WXBUTTON2 = 1010,
			ID_WXSTATICTEXT1 = 1009,
			ID_BMPOUTPUT1 = 1007,
			ID_BMPOUTPUT = 1006,
			ID_UPLOAD_BITMAP = 1003,
			ID_UPLOAD = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
double rgb_array[20][20];
double unrolledarray[1][400];
double Theta1[25][401];
double Theta1Trans[401][25];
double Theta2[10][26];
double Theta2Trans[26][10];
double input[1][401];
double conf[1];
double a_1[1][401];
double a_2[1][25];
double  a_3[1][10];
double confidence_a_3[1][10];
double mapped[1][400];
int uncalib_pred;
int calib_pred;
double a_2App[1][26];
double a_3_1;
double a_3_2;
double a_3_3;
double a_3_4;
double a_3_5;
double a_3_6;
double a_3_7;
double a_3_8;
double a_3_9;
double a_3_0;


};
#endif
