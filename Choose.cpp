#include "Choose.hpp"
#include <iostream>

Choose::Choose(int _posx, int _posy, int _sizex, int _sizey, int _px, int _py, int _row, int _r, int _g, int _b)
: Originalwidget(_posx, _posy, _sizex, _sizey, _px, _py, _row, _r, _g, _b)
{
base.open(sizex,sizex*10);
}

void Choose::draw()
{
    base << move_to(0,0) << color(255-r,255-g,255-b) << box(sizex,sizex*10);

    if (stringtext.size() != 0)
    {
        for (unsigned int i = 0; i < stringtext.size(); i++)
        {
            base << move_to(px,(gout.cascent()+gout.cdescent())*(i+1)) << color(r,g,b) << text(stringtext[i]);
            base << move_to(px,(gout.cascent()+gout.cdescent())*(reckon+1)) << color(r/2,g/2,b/2) << text(stringtext[reckon]);
            result = stringtext[reckon];
        }
    }

    gout << stamp(base, 0, counter, sizex, sizey, posx, posy);
}

void Choose::functionmake(event ev)
{

if (ev.button == btn_wheelup && focusban && counter >= 0)
{
    counter--;
}
if (ev.button == btn_wheeldown && focusban && counter+sizey-margin <= stringtext.size()*(gout.cascent()+gout.cdescent()))
{
    counter++;
}

if (ev.button == btn_left && focusban)
{
    number = (ev.pos_y - posy+counter)/(gout.cascent()+gout.cdescent());
    for (unsigned int i = 0; i < stringtext.size() && stringtext.size() != 0; i++)
    {
        if (number == i)
        {
            reckon = i;
        }
    }
}

if (focusban && ev.keycode == key_down && reckon < stringtext.size()-1)
{
    reckon++;
}
if (focusban && ev.keycode == key_up && reckon > 0)
{
    reckon--;
}

}

void Choose::ssetter3(vector<string> a)
{
    stringtext = a;
}

string Choose::sgetter(string a)
{

}

void Choose::ssetter()
{
    if ((1+reckon) != (stringtext.size())){
    stringtext.erase(stringtext.begin()+reckon);}
    else
    {
        reckon = reckon - 1;
        stringtext.pop_back();
        if (reckon < 0)
        {
            reckon = 0;
        }
    }
}
