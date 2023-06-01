#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <wx/datetime.h>
#include <wx/string.h>

#pragma once
struct AudioInfo
{
public:
	AudioInfo();
	AudioInfo(wxString filePath);

	wxString GetFilePath();
	wxString GetTitle();
	wxString GetAlbum();
	wxString GetArtist();
	wxString GetDurationString();
	wxTimeSpan GetDuration();

	bool SetFilePath(wxString filePath);

private:
	wxString filePath;
	wxString title;
	wxString album;
	wxString artist;
	wxString durationString;
	wxTimeSpan duration;
	bool isLiked;
};

