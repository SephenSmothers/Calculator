#include "ButtonFactory.h"

wxButton* ButtonFactory::CreateButton(wxWindow* _win, int _id, const char* _val, wxPoint _point, wxSize _size)
{
	newButton = new wxButton(_win, _id, _val, _point, _size);

	return newButton;
}
