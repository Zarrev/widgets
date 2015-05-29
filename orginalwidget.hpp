#ifndef ORGINALWIDGET_HPP_INCLUDED
#define ORGINALWIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

class Originalwidget
{
protected:

    int posx, posy, sizex, sizey, row, r, g, b, px, py;
    int upbar, downbar, randomthing, rand;
    int counter = 0, number = 0, reckon = 0, margin = 5;
    bool statictextbox = false, logical = false, unlogical = false, focusban = false, which = false, what = false, focuspocus = false;
    string textmess, textmass, usetext;
    vector<string> stringtext;
    vector<int> intnumber;

public:
    string result = "Nem lett kivalasztott elem.";
    Originalwidget(int _posx, int _posy, int _sizex, int _sizey);
    Originalwidget(int _posx, int _posy, int _sizex, int _sizey, int _row, int _r, int _g, int _b);
    Originalwidget(int _posx, int _posy, int _sizex, int _sizey, int _px, int _py, int _row, int _r, int _g, int _b);
    Originalwidget(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b);
    virtual void draw()  = 0;
    virtual void functionmake(event ev) = 0;
    virtual int igetter(int a) {};
    virtual void isetter() {};
    virtual string sgetter(string a) {};
    virtual void ssetter() {};
    virtual void focus(event ev, int a);
    virtual void isetter2() {};
    virtual void ssetter2(string a) {};
    virtual void ssetter3(vector<string> a) {};
    virtual vector<string> getter();

};

#endif // ORGINALWIDGET_HPP_INCLUDED
