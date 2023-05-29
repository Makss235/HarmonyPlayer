#include "PlaylistsData.h"

void PlaylistsData::Initialize(wxString filePath)
{
    PlaylistsData::filePath = filePath;

    wxTextFile jsonFile;
    jsonFile.Open(PlaylistsData::filePath);

    wxString textFromFile;
    for (wxString stringLine = jsonFile.GetFirstLine();
        !jsonFile.Eof(); stringLine = jsonFile.GetNextLine())
        textFromFile.append(stringLine);

    jsonFile.Close();

    Document document;
    document.Parse(textFromFile.c_str());

    for (size_t i = 0; i < document.Size(); i++)
    {
        PlaylistObject playlistObjectCurrent;

        playlistObjectCurrent.Name = document[i]["Name"].GetString();
        playlistObjectCurrent.IconSource = document[i]["IconSource"].GetString();
        playlistObjectCurrent.ID = document[i]["ID"].GetString();

        auto jj(document[i]["AudioSources"].GetArray());
        for (size_t i = 0; i < jj.Size(); i++)
            playlistObjectCurrent.AudioSources.Add(jj[i].GetString());

        playlistObjectsVector->push_back(playlistObjectCurrent);
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