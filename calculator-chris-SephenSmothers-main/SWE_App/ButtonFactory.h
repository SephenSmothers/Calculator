#pragma once
#include "MainWindow.h"

class ButtonFactory
{

private:
	wxButton* newButton = nullptr;

public:

	wxButton* CreateButton(wxWindow* _win, int _id, const char* _val, wxPoint _point, wxSize _size);
};

