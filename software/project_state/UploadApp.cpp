//---------------------------------------------------------------------------
//
// Name:        UploadApp.cpp
// Author:      user
// Created:     22/10/2018 3:39:40 PM
// Description: 
//
//---------------------------------------------------------------------------

#include "UploadApp.h"
#include "UploadFrm.h"

IMPLEMENT_APP(UploadFrmApp)

bool UploadFrmApp::OnInit()
{
    UploadFrm* frame = new UploadFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int UploadFrmApp::OnExit()
{
	return 0;
}
