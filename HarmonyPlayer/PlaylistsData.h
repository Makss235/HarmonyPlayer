#include <vector>
#include <wx/textfile.h>
#include <wx/wx.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "PlaylistInfo.h"
#include "PlaylistObject.h"

using namespace rapidjson;
using namespace std;

#pragma once
class PlaylistsData
{
public:
	static void Initialize(wxString filePath);
	static void Save();

	static wxString GetFilePath();
	static vector<PlaylistObject> *GetPlaylistObjects();
	static vector<PlaylistInfo> *GetPlaylistsInfo();

private:
	static wxString filePath;
	static vector<PlaylistObject> *playlistObjectsVector;
	static vector<PlaylistInfo> *playlistsInfoVector;
};