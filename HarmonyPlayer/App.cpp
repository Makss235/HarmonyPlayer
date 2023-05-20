#include "App.h"
#include "MainWindow.h"

bool App::OnInit()
{
    MainWindow* mainWindow = new MainWindow();
    mainWindow->Show(true);
    return true;
}