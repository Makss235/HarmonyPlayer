#pragma once
#include "wx/wx.h"

class MainWindow :
    public wxFrame
{
public:
    MainWindow();

private:

#pragma region Functions

    void InitializeComponent();
    wxPanel* ICMenuPlaylists();
    wxPanel* ICMainField();
    wxPanel* ICAudioStateRow();

#pragma endregion

    wxSize mainWindowSize = wxSize(900, 800);
    wxSize mainWindowMinSize = wxSize(600, 500);
    wxSize mainWindowMaxSize = wxSize(1100, 1000);
    wxSize audioStateRowSize = wxSize(mainWindowSize.GetWidth(), 70);
    wxSize menuPlaylistsSize = wxSize(250,
        mainWindowSize.GetHeight() - audioStateRowSize.GetHeight());
    wxSize mainFieldSize = wxSize(
        mainWindowSize.GetWidth() - menuPlaylistsSize.GetWidth(),
        mainWindowSize.GetHeight() - audioStateRowSize.GetHeight());
    wxSize mainFieldMinSize = wxSize(
        mainWindowMinSize.GetWidth() - menuPlaylistsSize.GetWidth(),
        mainWindowMinSize.GetHeight() - audioStateRowSize.GetHeight());
    wxSize mainFieldMaxSize = wxSize(
        mainWindowMaxSize.GetWidth() - menuPlaylistsSize.GetWidth(),
        mainWindowMaxSize.GetHeight() - audioStateRowSize.GetHeight());

    wxPanel* menuPlaylistsPanel;
    wxPanel* mainFieldPanel;
    wxPanel* audioStatePanel;

    wxBoxSizer* mainHorizontalBS;
    wxBoxSizer* mainVerticalBS;
};