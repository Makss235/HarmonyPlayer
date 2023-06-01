#include "CircleControl.h"

CircleControl::CircleControl() { }

CircleControl::CircleControl(wxWindow* parent, 
	wxWindowID id, const wxPoint& pos, 
	const wxSize& size, long style)
		: wxControl(parent, id, pos, size, style) { }

void CircleControl::OnPaint(wxPaintEvent& event)
{
    wxWindowDC dc(this);
    wxGCDC gdc(dc);
    wxBrush backgroundBrush(wxColour(14, 12, 30));
    gdc.SetBackground(backgroundBrush);
    gdc.Clear();
    wxBrush figureBrush(wxColour("white"));
    wxPen figurePen(wxColour(14, 12, 30), 1, wxPENSTYLE_TRANSPARENT);
    gdc.SetBrush(figureBrush);
    gdc.SetPen(figurePen);

    gdc.DrawEllipse(this->GetClientRect());
}

wxBEGIN_EVENT_TABLE(CircleControl, wxControl)
    EVT_PAINT(CircleControl::OnPaint)
wxEND_EVENT_TABLE()
