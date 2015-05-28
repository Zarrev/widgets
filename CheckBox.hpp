#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "orginalwidget.hpp"

class CheckBox : public Originalwidget
{
protected:


public:

    CheckBox(int _posx, int _posy, int _sizex, int _sizey, int _row, int _r, int _g, int _b);
    virtual void draw();
    virtual void functionmake(event ev);

};

#endif // CHECKBOX_HPP_INCLUDED
