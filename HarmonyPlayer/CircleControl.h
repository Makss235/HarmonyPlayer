#pragma once
#include <wx/control.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>

class CircleControl :
    public wxControl
{
public:
    CircleControl(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxBORDER_NONE)
        : wxControl(parent, id, pos, size, style) {
    }

protected:
    void OnPaint(wxPaintEvent& event)
    {
        // Create paint DC
        wxPaintDC dc(this);
        wxBrush brush(wxColor(255, 0, 0)); // Красный цвет
        wxPen pen(wxColor(wxTransparentColor), 1, wxPENSTYLE_TRANSPARENT); // Без видимой границы
        dc.SetBrush(brush);
        dc.SetPen(pen);

        dc.DrawCircle(6, 6, 6);
    }
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(CircleControl, wxControl)
    EVT_PAINT(CircleControl::OnPaint)
wxEND_EVENT_TABLE()