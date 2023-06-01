#include <wx/string.h>
#include <wx/datetime.h>
#include <vector>
#include "AudioInfo.h"
#include "PlaylistObject.h"

using namespace std;

#pragma once
struct PlaylistInfo
{
public:
	PlaylistInfo();
	PlaylistInfo(wxString name, wxString iconSource, 
		wxString id, vector<AudioInfo>* audioCompositions);
	PlaylistInfo(PlaylistObject playlistObject);

	wxString GetName();
	wxString GetIconSource();
	wxString GetID();
	wxString GetTotalDurationString();
	wxTimeSpan GetTotalDuration();
	vector<AudioInfo>* GetAudioCompositions();

private:
	void CalculatingTotalDuration();

	wxString name;
	wxString iconSource;
	wxString id;
	wxString totalDurationString;
	wxTimeSpan totalDuration;
	vector<AudioInfo>* audioCompositions;
};
