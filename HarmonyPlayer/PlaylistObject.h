#include <wx/string.h>
#include <vector>

using namespace std;

#pragma once
struct PlaylistObject
{
public:
	wxString Name;
	wxString IconSource;
	wxString ID;
	vector<wxString>* AudioSources;
};

