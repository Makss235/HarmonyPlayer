#pragma once
#include <wx/control.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>
#include <wx/dcgraph.h>

class CircleControl :
    public wxControl
{
public:
    CircleControl();
    CircleControl(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxBORDER_NONE);

protected:
    void OnPaint(wxPaintEvent& event);
    wxDECLARE_EVENT_TABLE();
};