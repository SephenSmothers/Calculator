#include "WidgetsAppMain.h"
#include "MainWindow.h"


wxIMPLEMENT_APP(WidgetsAppMain);

bool WidgetsAppMain::OnInit()
{
	mMainWindow = new MainWindow();
	mMainWindow->Show();
	return true;
}