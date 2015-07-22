
// Bejeweled2 Deluxe Cheat Tool.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBejeweled2DeluxeCheatToolApp:
// See Bejeweled2 Deluxe Cheat Tool.cpp for the implementation of this class
//

class CBejeweled2DeluxeCheatToolApp : public CWinApp
{
public:
	CBejeweled2DeluxeCheatToolApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBejeweled2DeluxeCheatToolApp theApp;