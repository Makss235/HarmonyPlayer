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

	CalculatingTotalDuration();
}

PlaylistInfo::PlaylistInfo(PlaylistObject playlistObject)
{
	name = playlistObject.Name;
	iconSource = playlistObject.IconSource;
	id = playlistObject.ID;

	audioCompositions = new vector<AudioInfo>();
	for (int i = 0; i < playlistObject.AudioSources->size(); i++)
		audioCompositions->push_back(AudioInfo(playlistObject.AudioSources->at(i)));

	totalDuration = wxTimeSpan();
	totalDurationString = wxString();

	CalculatingTotalDuration();
}

PlaylistInfo::PlaylistInfo()
{
	name = wxString();
	iconSource = wxString();
	id = wxString();
	audioCompositions = new vector<AudioInfo>();
	totalDuration = wxTimeSpan();
	totalDurationString = wxString();
}

wxString PlaylistInfo::GetName() {
	return name;
}

wxString PlaylistInfo::GetIconSource() {
	return iconSource;
}

wxString PlaylistInfo::GetID() {
	return id;
}

wxString PlaylistInfo::GetTotalDurationString() {
	return totalDurationString;
}

wxTimeSpan PlaylistInfo::GetTotalDuration() {
	return totalDuration;
}

vector<AudioInfo>* PlaylistInfo::GetAudioCompositions() {
	return audioCompositions;
}

void PlaylistInfo::CalculatingTotalDuration()
{
	totalDuration = wxTimeSpan();
	for(vector<AudioInfo>::iterator iter = audioCompositions->begin(); 
		iter != audioCompositions->end(); iter++)
	{
		totalDuration += (*iter).GetDuration();
	}
	totalDurationString = totalDuration.Format("%H:%M:%S");
}
