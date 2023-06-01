#include "App.h"

bool App::OnInit()
{
    InitializeData();

    MainWindow* mainWindow = new MainWindow();
    mainWindow->Show(true);
    return true;
}

void App::InitializeData()
{
    PlaylistsData::Initialize("Playlists.json");
}
