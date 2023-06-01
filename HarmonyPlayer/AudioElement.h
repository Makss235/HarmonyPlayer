#pragma once
#include "wx/wx.h"
#include "AudioInfo.h"

class AudioElement :
    public wxPanel
{
public:
    AudioElement();

    AudioElement(AudioInfo audioInfo, 
        wxWindow* parent,
        wxWindowID winid = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxTAB_TRAVERSAL | wxNO_BORDER,
        const wxString& name = wxASCII_STR(wxPanelNameStr));

private:
    void InitializeComponent();

    AudioInfo audioInfo;
};

