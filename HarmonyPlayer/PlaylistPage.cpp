#include "PlaylistPage.h"
#include "CircleControl.h"
#include "AudioInfo.h"
#include "PlaylistsData.h"

PlaylistPage::PlaylistPage(wxWindow* parent,
	wxWindowID winid, const wxPoint& pos,
	const wxSize& size, long style, const wxString& name) :
		wxPanel(parent, winid, pos, size, style, name)
{
	InitializeComponent();
}

PlaylistPage::~PlaylistPage() { }

void PlaylistPage::InitializeComponent()
{
	int heightHeaderPanel = 188;

	wxPanel* headerPlaylistPanel = new wxPanel(this, wxID_ANY,
		wxDefaultPosition, wxSize(GetSize().GetWidth(), heightHeaderPanel));
	//headerPlaylistPanel->SetBackgroundColour(wxColour(55, 111, 30));

	wxImage::AddHandler(new wxPNGHandler);
	wxBitmap bitmap(wxT("pl1.png"), wxBITMAP_TYPE_PNG);
	bitmap.Rescale(bitmap, wxSize(128, 128));
	wxStaticBitmap* bitmapControl = new wxStaticBitmap(
		headerPlaylistPanel, wxID_ANY, bitmap);

	wxStaticText* text = new wxStaticText(headerPlaylistPanel, wxID_ANY, "Любимые треки");
	text->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	text->SetForegroundColour(wxColour("white"));


	PlaylistsData::Initialize("Playlists.json");
	wxMessageBox(PlaylistsData::GetPlaylistsInfo()->at(0).GetAudioCompositions()->at(5).GetTitle());


	wxStaticText* text1 = new wxStaticText(headerPlaylistPanel, wxID_ANY, "Любимые треки");
	text1->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	text1->SetForegroundColour(wxColour("white"));

	CircleControl* cc = new CircleControl(headerPlaylistPanel, wxID_ANY, 
		wxDefaultPosition, wxSize(8, 8));

	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	box->Add(text1, 0, 0, 0);
	box->Add(cc, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 8);

	wxBoxSizer* bb = new wxBoxSizer(wxVERTICAL);
	bb->Add(text, 0, 0, 0);
	bb->Add(box, 0, wxTOP, 12);

	int alignImage = (heightHeaderPanel - bitmapControl->GetSize().GetHeight()) / 2;
	wxBoxSizer* headerHorizSizer = new wxBoxSizer(wxHORIZONTAL);
	headerHorizSizer->Add(bitmapControl, 0, wxALIGN_CENTER | wxALL, 30);
	headerHorizSizer->Add(bb, 0, wxALIGN_CENTER | wxLEFT, 10);

	headerPlaylistPanel->SetSizer(headerHorizSizer);
	headerPlaylistPanel->Layout();

	wxBoxSizer* mainVertSizer = new wxBoxSizer(wxVERTICAL);
	mainVertSizer->Add(headerPlaylistPanel, 0, wxEXPAND);

	SetSizer(mainVertSizer);
	Layout();
}
