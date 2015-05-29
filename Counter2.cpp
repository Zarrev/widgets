#include "Counter2.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>


Counter2::Counter2(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b,  int _upbar, int _downbar)
: Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
{
    upbar = _upbar;
    downbar = _downbar;
    margin = 0;
    randomthing = 0;
    if (downbar <= 0)
    {
        counter = upbar+(-1)*downbar;
        number = 0;
    }
    else
    {
        counter = upbar-downbar;
        number = _downbar;
    }
    reckon = sizex*(sizex/counter);
    stringstream ss;
    ss << number;
    textmess = ss.str();
    ss.clear();
}

void Counter2::value(event ev)
{
        if (logical)
        {
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }
        if (unlogical)
        {
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
        }

    if (focusban)
    {
        if (ev.keycode == key_up)
        {
            number = upbar;
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
            which = true;
            what = false;
        }
        if (ev.keycode == key_down)
        {
            number = downbar;
            stringstream ss;
            ss << number;
            textmess = ss.str();
            ss.clear();
            what = true;
            which = false;
        }
    }
}

void Counter2::draw()
{
    gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << color(255-r,255-g,255-b) << move_to(posx+margin,posy) << box(reckon/sizex,sizey);
}

void Counter2::functionmake(event ev)
{
    static int zero = 0;
    if (downbar <= 0 && zero == 0)
    {
        margin = abs(downbar*reckon/sizex);
    }
    else if (downbar > 0 && zero == 0)
    {
        number = downbar;
    }
    zero++;
    value(ev);
    if (what)
    {
        randomthing = margin;
        margin = 0;
        reckon = sizex*(sizex/counter);
        what = false;
    }
    if (which)
    {
        randomthing = margin;
        margin = 0;
        reckon = sizex*sizex;
        which = false;
    }

    if (number == upbar-1)
    {
        reckon = sizex*(sizex/counter);
        margin = sizex-reckon/sizex;

    }
}

string Counter2::sgetter(string a)
{
    return textmess;
}

void Counter2::isetter()
{
    if (number < upbar-1)
    {
        margin += reckon/sizex;
        number++;
        logical = true;
        randomthing = margin;
        unlogical = false;
    }
    else if (number < upbar)
    {
        logical = true;
        unlogical = false;
        number++;
        margin = 0;
        reckon = sizex*sizex;
    }

}
void Counter2::isetter2()
{
    if (number == upbar)
    {
        if (downbar <= 0)
        {
            counter = upbar+(-1)*downbar;
        }
        else
        {
            counter = upbar-downbar;
        }
        reckon = sizex*(sizex/counter);
        margin = randomthing+reckon/sizex;
    }

    if (number > downbar && posx < posx+margin) //(margin >= posx-reckon/sizex)
    {
        margin -= reckon/sizex;
        number--;
        unlogical = true;
        logical = false;
    }
}
