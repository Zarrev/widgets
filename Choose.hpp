#ifndef CHOOSE_HPP_INCLUDED
#define CHOOSE_HPP_INCLUDED

#include "orginalwidget.hpp"

class Choose : public Originalwidget
{
protected:

    virtual void value (){};
    canvas base;

public:

    Choose(int _posx, int _posy, int _sizex, int _sizey, int _px, int _py, int _row, int _r, int _g, int _b);
    virtual void draw() ;
    virtual void functionmake(event ev);
    virtual string sgetter(string a);
    virtual void ssetter();
    virtual void ssetter3(vector<string> a);

};

#endif // CHOOSE_HPP_INCLUDED
