#include "AudioElement.h"

AudioElement::AudioElement() { }

AudioElement::AudioElement(AudioInfo audioInfo, 
	wxWindow* parent, wxWindowID winid, const wxPoint& pos, 
	const wxSize& size, long style, const wxString& name)
	: wxPanel(parent, winid, pos, size, style, name)
{
	this->audioInfo = audioInfo;

	InitializeComponent();
}

void AudioElement::InitializeComponent()
{
	wxStaticText* titleText = new wxStaticText(this, wxID_ANY, audioInfo.GetTitle(), wxDefaultPosition, wxSize(300, 50));
	titleText->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	titleText->SetForegroundColour(wxColour("white"));

	wxStaticText* artistText = new wxStaticText(this, wxID_ANY, audioInfo.GetArtist());
	artistText->SetFont(wxFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	artistText->SetForegroundColour(wxColour("white"));

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);
	mainSizer->Add(titleText, 0, 0, 0);
	mainSizer->Add(artistText, 0, 0, 0);

	SetSizer(mainSizer);
	Layout();
}
