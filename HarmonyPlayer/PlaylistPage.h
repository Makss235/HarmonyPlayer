#pragma once
#include <wx/wx.h>
#include "PlaylistInfo.h"
#include "PlaylistsData.h"
//#include "CircleControl.h"
#include "AudioInfo.h"

class PlaylistPage : 
	public wxPanel
{
public:
	PlaylistPage(PlaylistInfo info,
		wxWindow* parent,
		wxWindowID winid = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxTAB_TRAVERSAL | wxNO_BORDER,
		const wxString& name = wxASCII_STR(wxPanelNameStr));
	~PlaylistPage();

	PlaylistInfo GetInfo();
	bool SetInfo(PlaylistInfo info);

private:
	void InitializeComponent();
	wxPanel* ICHeaderPanel();

	PlaylistInfo info;
	int heightHeaderPanel = 188;

	wxPanel* headerPlaylistPanel;
	wxBitmap bitmapIconPlaylist;
	wxStaticBitmap* bitmapIconHeaderControl;
	wxStaticText* nameText;
	wxStaticText* quantityTracksText;
	//CircleControl* separatorCircle;
	wxStaticText* totalDurationText;
	wxBoxSizer* additionalInfoSizer;
	wxBoxSizer* allInfoSizer;
	wxBoxSizer* headerHorizSizer;

	wxBoxSizer* mainVertSizer;
};