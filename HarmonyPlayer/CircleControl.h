#pragma once
#include <wx/control.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>

class CircleControl :
    public wxControl
{
public:
    CircleControl() { }

    CircleControl(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxBORDER_NONE)
        : wxControl(parent, id, pos, size, style) {
    }

protected:
    void OnPaint(wxPaintEvent& event)
    {
        wxPaintDC dc(this);
        wxBrush brush(wxColour(14, 12, 30));
        dc.SetBackground(brush);
        dc.Clear();
        wxBrush brush1(wxColour("white"));
        wxPen pen(wxColour(14, 12, 30), 1, wxPENSTYLE_TRANSPARENT);
        dc.SetBrush(brush1);
        dc.SetPen(pen);

        dc.DrawCircle(4, 4, 4);
    }
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(CircleControl, wxControl)
    EVT_PAINT(CircleControl::OnPaint)
wxEND_EVENT_TABLE()