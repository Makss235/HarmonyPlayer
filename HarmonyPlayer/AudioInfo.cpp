#include "AudioInfo.h"

AudioInfo::AudioInfo(wxString filePath)
{
    this->filePath = filePath;

    TagLib::FileRef file(TagLib::FileName(this->filePath.mb_str(wxConvUTF8)));
    if (file.isNull()) 
    {
        return;
    }

    TagLib::Tag* tag = file.tag();
    if (tag == nullptr) 
    {
        return;
    }

    title = tag->title().toCString();
    album = tag->album().toCString();
    artist = tag->artist().toCString();
    duration = wxTimeSpan(0, 0, 0, file.audioProperties()->lengthInMilliseconds());
    durationString = duration.Format("%M:%S");
    isLiked = false;
}

wxString AudioInfo::GetFilePath()
{
    return filePath;
}

wxString AudioInfo::GetTitle()
{
    return title;
}

wxString AudioInfo::GetAlbum()
{
    return album;
}

wxString AudioInfo::GetArtist()
{
    return artist;
}

wxString AudioInfo::GetDurationString()
{
    return durationString;
}

wxTimeSpan AudioInfo::GetDuration()
{
    return duration;
}

bool AudioInfo::SetFilePath(wxString filePath)
{
    this->filePath = filePath;
    return true;
}
