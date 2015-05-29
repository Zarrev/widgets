#include "CheckBox.hpp"
#include <iostream>

CheckBox::CheckBox(int _posx, int _posy, int _sizex, int _sizey, int _row, int _r, int _g, int _b)
: Originalwidget(_posx, _posy, _sizex, _sizey, _row, _r, _g, _b) {}

void CheckBox::draw()
{
    if (unlogical)
    {
        gout << move_to(posx, posy) << color(r,g,b) << box(sizex,sizey);
        gout << move_to(posx+margin, posy+margin) << color(255-r,255-g,255-b) << box(sizex-2*margin-1,sizey-2*margin-1);
    }
    else
    {
        gout << move_to(posx, posy) << color(r,g,b) << box(sizex,sizey);
    }
}

void CheckBox::functionmake(event ev)
{
    if (focusban)
    {
        if (posx <= ev.pos_x && posx+sizex >= ev.pos_x && posy <= ev.pos_y && posy+sizey >= ev.pos_y && ev.button == btn_left)
        {
            counter++;
        }
        if (counter%2 != 0)
        {
            unlogical = true;
            result = "true";
        }
        else
        {
            unlogical = false;
            result = "false";
        }
    }
}
