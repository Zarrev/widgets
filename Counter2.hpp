#ifndef COUNTER2_HPP_INCLUDED
#define COUNTER2_HPP_INCLUDED

#include "orginalwidget.hpp"

class Counter2 : public Originalwidget
{
protected:

    virtual void value (event ev);

public:

    Counter2(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b,  int _upbar, int _downbar);
    virtual void draw() ;
    virtual void functionmake(event ev);
    virtual void isetter();
    virtual void isetter2();
    virtual string sgetter(string a);
};

#endif // COUNTER2_HPP_INCLUDED
