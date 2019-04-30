//---------------------------------------------------------------------------
//
// Name:        UploadApp.h
// Author:      user
// Created:     22/10/2018 3:39:40 PM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __UPLOADFRMApp_h__
#define __UPLOADFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class UploadFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
