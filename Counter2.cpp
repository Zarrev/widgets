#include "Counter2.hpp"
#include <string>
#include <sstream>
#include <iostream>


Counter2::Counter2(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b,  int _upbar, int _downbar)
: Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
{
    upbar = _upbar;
    downbar = _downbar;
    number = _downbar;
    margin = 0;
    if (downbar < 0)
    {
        counter = upbar+(-1)*downbar;
    }
    else
    {
        counter = upbar+downbar;
    }
    reckon = sizex*(sizex/counter);
}

void Counter2::value(event ev)
{
    if ((ev.button == btn_left xor ev.keycode == key_up xor ev.keycode == key_down) && focusban)
    {
        if (logical)
        {
            if (number < upbar)
            {
                number++;
            }
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }
        if (unlogical)
        {
            if (number > downbar)
            {
                number--;
            }
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }
    }
    if ((ev.keycode == key_pgup xor ev.keycode == key_pgdn)&&focusban)
    {
        if (logical)
        {
            number = upbar;
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }
        if (unlogical)
        {
            number = downbar;
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }
    }
}

void Counter2::draw()
{
    gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << color(255-r,255-g,255-b) << move_to(posx+margin,posy) << box(reckon/sizex,sizey);
}

void Counter2::functionmake(event ev)
{
    value(ev);
}

string Counter2::sgetter(string a)
{
    a = textmess;
    return a;
}

void Counter2::isetter()
{
    if (margin <= sizex-margin/2)
    {
        margin += reckon/sizex;
        number++;
    }
}
void Counter2::isetter2()
{
    if (margin >= posx)
    {
        margin -= reckon/sizex;
        number--;
    }
}
