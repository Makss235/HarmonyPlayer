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

    wxPanel* menuPlaylistsPanel;
    wxPanel* mainFieldPanel;
    wxPanel* audioStatePanel;

    wxBoxSizer* mainHorizontalBS;
    wxBoxSizer* mainVerticalBS;
};