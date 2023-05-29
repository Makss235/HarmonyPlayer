#include <wx/wx.h>
#include <vector>
#include "AudioInfo.h"
#include "PlaylistObject.h"

using namespace std;

#pragma once
struct PlaylistInfo
{
public:
	PlaylistInfo(wxString name, wxString iconSource, 
		wxString id, vector<AudioInfo>* audioCompositions);
	PlaylistInfo(PlaylistObject playlistObject);

private:
	wxString name;
	wxString iconSource;
	wxString id;
	wxString totalDurationString;
	wxTimeSpan totalDuration;
	vector<AudioInfo>* audioCompositions;
};
