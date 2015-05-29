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
            base << move_to(px,(gout.cascent()+gout.cdescent())*(i+1)+counter) << color(255,0,0) << text(stringtext[i]);
        }
    }

    gout << stamp(base, 0, 0, sizex, sizex, posx, posy);
}

void Choose::functionmake(event ev)
{
if (ev.button == btn_wheelup )
{
    counter--;
}
if (ev.button == btn_wheeldown)
{
    counter++;
}

if (ev.button == btn_left && focusban) // ay indexkkel kell vararzsolni
{
     std::cout << (ev.pos_y - posy-counter)/(gout.cascent()+gout.cdescent()) << std::endl;
}

}

void Choose::ssetter3(vector<string> a)
{
    stringtext = a;
    std::cout << stringtext[0] << endl;
}

string Choose::sgetter(string a)
{

}

void Choose::value()
{

}
