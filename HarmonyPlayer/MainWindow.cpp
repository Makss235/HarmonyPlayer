#include "MainWindow.h"

MainWindow::MainWindow()
    : wxFrame(nullptr, wxID_ANY, "HarmonyPlayer", 
        wxDefaultPosition, wxSize(900, 800), 
        wxFRAME_SHAPED | wxBORDER_NONE | wxRESIZE_BORDER)
{
    //Это код для создания закруглений, создается белая граница
    /*wxGraphicsPath path = wxGraphicsRenderer::GetDefaultRenderer()->CreatePath();
    path.AddRoundedRectangle(0, 0, 900, 800, 10);
    SetShape(path);*/

    SetSizeHints(wxSize(500, 500), wxSize(1100, 1000));
    CenterOnScreen();

    SetBackgroundColour(wxColour(14, 12, 30));

    InitializeComponent();
}

void MainWindow::InitializeComponent()
{
    mainHorizontalBS = new wxBoxSizer(wxHORIZONTAL);
    mainHorizontalBS->Add(ICMenuPlaylists(), 0, wxEXPAND);
    mainHorizontalBS->Add(ICMainField(), -1, wxEXPAND);

    mainVerticalBS = new wxBoxSizer(wxVERTICAL);
    mainVerticalBS->Add(mainHorizontalBS, -1, wxEXPAND);
    mainVerticalBS->Add(ICAudioStateRow(), 0, wxEXPAND);

    SetSizer(mainVerticalBS);
    Layout();
}

wxPanel* MainWindow::ICMenuPlaylists()
{
    menuPlaylistsPanel = new wxPanel(this, wxID_ANY, 
        wxDefaultPosition, wxSize(250, 100));
    menuPlaylistsPanel->SetBackgroundColour(wxColour(14, 11, 30));

    return menuPlaylistsPanel;
}

wxPanel* MainWindow::ICMainField()
{
    mainFieldPanel = new wxPanel(this, wxID_ANY,
        wxDefaultPosition, wxSize(100, 100));
    mainFieldPanel->SetBackgroundColour(wxColour(44, 222, 30));

    return mainFieldPanel;
}

wxPanel* MainWindow::ICAudioStateRow()
{
    audioStatePanel = new wxPanel(this, wxID_ANY,
        wxDefaultPosition, wxSize(100, 70));
    audioStatePanel->SetBackgroundColour(wxColour(14, 22, 77));

    return audioStatePanel;
}
