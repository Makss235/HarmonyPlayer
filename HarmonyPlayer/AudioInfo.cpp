#include "AudioInfo.h"

AudioInfo::AudioInfo(wxString filePath)
{
    this->filePath = filePath;

    TagLib::FileRef file(TagLib::FileName(this->filePath.mb_str()));
    if (file.isNull()) 
    {
        return;
    }

    TagLib::Tag* tag = file.tag();
    if (tag == nullptr) 
    {
        return;
    }

    /*auto gg = tag->title().to8Bit(true);
    auto gg1 = tag->title().to8Bit();

    wxString title1 = tag->title().toCString();
    wxString title2 = tag->title().toCString(true);*/

    title = tag->title().toCString();
    //wxString title11 = wxString::From8BitData(tag->title().toCString());

    album = tag->album().toCString();
    artist = tag->artist().toCString();
    duration = wxTimeSpan(0, 0, 0, file.audioProperties()->lengthInMilliseconds());
    durationString = duration.Format("%M:%S");
    isLiked = false;
}

wxString AudioInfo::GetFilePath() {
    return filePath;
}

wxString AudioInfo::GetTitle() {
    return title;
}

wxString AudioInfo::GetAlbum() {
    return album;
}

wxString AudioInfo::GetArtist() {
    return artist;
}

wxString AudioInfo::GetDurationString() {
    return durationString;
}

wxTimeSpan AudioInfo::GetDuration() {
    return duration;
}

bool AudioInfo::SetFilePath(wxString filePath)
{
    this->filePath = filePath;
    return true;
}
