#pragma once
#include <wx/wx.h>
#include "PlaylistInfo.h"

class PlaylistPage : 
	public wxPanel
{
public:
	PlaylistPage(wxWindow* parent,
		wxWindowID winid = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxTAB_TRAVERSAL | wxNO_BORDER,
		const wxString& name = wxASCII_STR(wxPanelNameStr));

	~PlaylistPage();

	PlaylistInfo GetInfo() {
		return info;
	}
	bool SetInfo(PlaylistInfo info) {
		PlaylistPage::info = info;
		return true;
	}
private:
	void InitializeComponent();

	PlaylistInfo info;
};

