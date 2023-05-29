#include "PlaylistInfo.h"

PlaylistInfo::PlaylistInfo(wxString name, wxString iconSource,
	wxString id, vector<AudioInfo>* audioCompositions)
{
	this->name = name;
	this->iconSource = iconSource;
	this->id = id;
	this->audioCompositions = audioCompositions;
	this->totalDuration = wxTimeSpan();
	this->totalDurationString = wxString();
}

PlaylistInfo::PlaylistInfo(PlaylistObject playlistObject)
{
	name = playlistObject.Name;
	iconSource = playlistObject.IconSource;
	id = playlistObject.ID;

	audioCompositions = new vector<AudioInfo>();
	this->totalDuration = wxTimeSpan();
	this->totalDurationString = wxString();
}
