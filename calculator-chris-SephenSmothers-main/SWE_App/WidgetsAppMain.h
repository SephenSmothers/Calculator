#pragma once
#include "wx/wx.h"

class MainWindow;

class WidgetsAppMain : public wxApp
{
	MainWindow* mMainWindow = nullptr;

public:

	virtual bool OnInit();
};

