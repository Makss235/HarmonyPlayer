#include <wx/wx.h>

#pragma once
struct PlaylistObject
{
public:
	wxString Name;
	wxString IconSource;
	wxString ID;
	wxArrayString AudioSources;
};

