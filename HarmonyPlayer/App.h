#pragma once
#include "wx/wx.h"
#include "MainWindow.h"
#include "PlaylistsData.h"

class App :
	public wxApp
{
public:
	bool OnInit() override;

private:
	void InitializeData();
};

