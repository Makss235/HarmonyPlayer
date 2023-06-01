#include "PlaylistPage.h"
#include "CircleControl.h"

PlaylistPage::PlaylistPage(PlaylistInfo info,
	wxWindow* parent,
	wxWindowID winid, const wxPoint& pos,
	const wxSize& size, long style, const wxString& name) :
		wxPanel(parent, winid, pos, size, style, name)
{
	PlaylistPage::info = info;

	InitializeComponent();
}

PlaylistPage::~PlaylistPage() { }

PlaylistInfo PlaylistPage::GetInfo() {
	return info;
}

bool PlaylistPage::SetInfo(PlaylistInfo info) {
	PlaylistPage::info = info;
	return true;
}

void PlaylistPage::InitializeComponent()
{
	mainVertSizer = new wxBoxSizer(wxVERTICAL);
	mainVertSizer->Add(ICHeaderPanel(), 0, wxEXPAND);

	SetSizer(mainVertSizer);
	Layout();
}

wxPanel* PlaylistPage::ICHeaderPanel()
{
	headerPlaylistPanel = new wxPanel(this, wxID_ANY,
		wxDefaultPosition, wxSize(GetSize().GetWidth(), heightHeaderPanel));

	wxImage::AddHandler(new wxPNGHandler);
	bitmapIconPlaylist = wxBitmap(info.GetIconSource(), wxBITMAP_TYPE_PNG);
	bitmapIconPlaylist.Rescale(bitmapIconPlaylist, wxSize(128, 128));
	bitmapIconHeaderControl = new wxStaticBitmap(
		headerPlaylistPanel, wxID_ANY, bitmapIconPlaylist);

	nameText = new wxStaticText(headerPlaylistPanel, wxID_ANY, info.GetName());
	nameText->SetFont(wxFont(23, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	nameText->SetForegroundColour(wxColour("white"));

	string quantityTracksString = to_string(info.GetAudioCompositions()->size()) + " треков";
	quantityTracksText = new wxStaticText(headerPlaylistPanel, wxID_ANY, quantityTracksString);
	quantityTracksText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	quantityTracksText->SetForegroundColour(wxColour("white"));

	separatorCircle = new CircleControl(headerPlaylistPanel, wxID_ANY,
		wxDefaultPosition, wxSize(8, 8));

	totalDurationText = new wxStaticText(headerPlaylistPanel, wxID_ANY, info.GetTotalDurationString());
	totalDurationText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	totalDurationText->SetForegroundColour(wxColour("white"));

	additionalInfoSizer = new wxBoxSizer(wxHORIZONTAL);
	additionalInfoSizer->Add(quantityTracksText, 0, 0, 0);
	additionalInfoSizer->Add(separatorCircle, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 13);
	additionalInfoSizer->Add(totalDurationText, 0, 0, 0);

	allInfoSizer = new wxBoxSizer(wxVERTICAL);
	allInfoSizer->Add(nameText, 0, 0, 0);
	allInfoSizer->Add(additionalInfoSizer, 0, wxTOP, 12);

	headerHorizSizer = new wxBoxSizer(wxHORIZONTAL);
	headerHorizSizer->Add(bitmapIconHeaderControl, 0, wxALIGN_CENTER | wxALL, 30);
	headerHorizSizer->Add(allInfoSizer, 0, wxALIGN_CENTER | wxLEFT, 10);

	headerPlaylistPanel->SetSizer(headerHorizSizer);
	headerPlaylistPanel->Layout();

	return headerPlaylistPanel;
}
