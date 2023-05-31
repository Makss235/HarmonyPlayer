#include "PlaylistsData.h"
#include <sstream>
#include <codecvt>

typedef GenericDocument<UTF16<>> WDocument;

void PlaylistsData::Initialize(wxString filePath)
{
    PlaylistsData::filePath = filePath;

    std::wifstream wif(PlaylistsData::filePath.mb_str());
    wif.imbue(locale(locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    wstring textFromFile = wss.str();

    WDocument document;
    document.Parse(textFromFile.c_str());

    for (size_t i = 0; i < document.Size(); i++)
    {
        PlaylistObject playlistObjectCurrent;
        playlistObjectCurrent.Name = document[i][L"Name"].GetString();
        playlistObjectCurrent.IconSource = document[i][L"IconSource"].GetString();
        playlistObjectCurrent.ID = document[i][L"ID"].GetString();
        playlistObjectCurrent.AudioSources = new vector<wxString>();

        auto audioSourcesArray(document[i][L"AudioSources"].GetArray());
        for (size_t i = 0; i < audioSourcesArray.Size(); i++)
            playlistObjectCurrent.AudioSources->push_back(audioSourcesArray[i].GetString());

        playlistObjectsVector->push_back(playlistObjectCurrent);
        playlistsInfoVector->push_back(PlaylistInfo(playlistObjectCurrent));
    }
}

void PlaylistsData::Save() { }

wxString PlaylistsData::GetFilePath() {
	return filePath;
}

vector<PlaylistObject>* PlaylistsData::GetPlaylistObjects() {
    return playlistObjectsVector;
}

vector<PlaylistInfo>* PlaylistsData::GetPlaylistsInfo() {
    return playlistsInfoVector;
}

vector<PlaylistObject> *PlaylistsData::playlistObjectsVector = new vector<PlaylistObject>();
vector<PlaylistInfo> *PlaylistsData::playlistsInfoVector = new vector<PlaylistInfo>();
wxString PlaylistsData::filePath = wxString();

