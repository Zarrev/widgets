#include "Button.hpp"
#include <iostream>

Button::Button(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b, string _textmass, function<void()> _f)
    : Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
    {
        textmass = _textmass;
        f = _f;
    }

void Button::draw()
{
    gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << move_to(posx+sizex/2-gout.twidth(usetext)/2,posy+sizey/2+(gout.cascent()+gout.cdescent())/2-2) << color(255-r,255-g,255-b) << text(usetext);


    if (focusban && logical)
    {
        gout << move_to(posx,posy) << color(255-r,255-g,255-b) << box(sizex,sizey) << move_to(posx+sizex/2-gout.twidth(usetext)/2,posy+sizey/2+(gout.cascent()+gout.cdescent())/2-2) << color(r,g,b) << text(usetext);
    }
    else if (!logical)
    {
        ssetter();
        gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << move_to(posx+sizex/2-gout.twidth(usetext)/2,posy+sizey/2+(gout.cascent()+gout.cdescent())/2-2) << color(255-r,255-g,255-b) << text(usetext);
    }
}

void Button::functionmake(event ev)
{

    if (focusban)
    {
        if (ev.button == btn_left)
        {
            if (posx+sizex >= ev.pos_x && posx <= ev.pos_x && posy <= ev.pos_y && posy+sizey >= ev.pos_y )
            {
                logical = true;
                if (textmass != "")
                {
                    usetext = textmass;
                }
                f();
            }
        }
        if (ev.button == -btn_left)
        {
                logical = false;
        }
    }
    if (focusban)
    {
        if (ev.keycode == key_up xor ev.keycode == key_pgup)
        {
            logical = true;
            if (textmass != "")
                {
                    usetext = textmass;
                }
            f();
        }
        if (ev.keycode == -key_up xor ev.keycode == -key_pgup)
        {
            logical = false;
        }
    }
    if (!focusban)
    {
       logical = false;
    }
}
void Button::ssetter()
{
    usetext = textmess;
}
