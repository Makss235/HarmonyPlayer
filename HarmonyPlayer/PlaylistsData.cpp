#include "PlaylistsData.h"

void PlaylistsData::Initialize(wxString filePath)
{
    PlaylistsData::filePath = filePath;

    string line;
    string textFromFile = "";
    ifstream ghgh(PlaylistsData::filePath.mb_str());

    while (getline(ghgh, line))
    {
        textFromFile.append(line);
    }

    Document document;
    document.Parse(textFromFile.c_str());

    for (size_t i = 0; i < document.Size(); i++)
    {
        PlaylistObject playlistObjectCurrent;

        playlistObjectCurrent.Name = document[i]["Name"].GetString();
        playlistObjectCurrent.IconSource = document[i]["IconSource"].GetString();
        playlistObjectCurrent.ID = document[i]["ID"].GetString();
        playlistObjectCurrent.AudioSources = new vector<wxString>();

        auto audioSourcesArray(document[i]["AudioSources"].GetArray());
        for (size_t i = 0; i < audioSourcesArray.Size(); i++)
        {
            auto a = audioSourcesArray[i].GetString();

            playlistObjectCurrent.AudioSources->push_back("hh");
        }

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