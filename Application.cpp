#include "graphics.hpp"
#include "Application.hpp"
#include "orginalwidget.hpp"
#include "CheckBox.hpp"
#include "textbox.hpp"
#include "Counter.hpp"
#include "Counter2.hpp"
#include "Select.hpp"
#include "Button.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Application::Application(int _SX, int _SY) : SX(_SX), SY(_SY) {}

void Application::run()
{
    gout.open(SX,SY);
    event ev;
    gin.timer(20);
    vector<Originalwidget*> Widget;
    Widget.push_back(new Textbox(20,20,100,25,"Ez egy StaticTextBox",1,255,0,0,true));
    Widget.push_back(new Counter(20,50,100,25,"0",2,20,20,20,100,-5));
    Widget.push_back(new Textbox(20,80,100,25,"--",3,150,150,150,false));
    Widget.push_back(new Select(20,170,100,50,"--",5,0,0,0));
    Widget.push_back(new Button(20,110,100,25,"+",4,600,600,1000,"+++",[&]()
    {

    }));
    string textma = "--";
    Widget.push_back(new CheckBox(20,140,25,25,6,255,0,0));
    Widget.push_back(new CheckBox(50,140,25,25,6,0,255,0));
    Widget.push_back(new Counter2(20,250,100,25,"0",2,20,20,20,5,0));
    Widget.push_back(new Button(130,250,50,25,"+",4,600,600,1000,"++",[&]()
    {
        for (Originalwidget* w : Widget)
        {
            if(Counter2* o = (dynamic_cast <Counter2*>(w)))
            {
                o -> isetter();
                o -> sgetter(textma);
            }
        }
    }));
    Widget.push_back(new Button(190,250,50,25,"-",4,600,600,1000,"--",[&]()
    {
        for (Originalwidget* w : Widget)
        {
            if(Counter2* o = (dynamic_cast <Counter2*>(w)))
            {
                o -> isetter2();
                o -> sgetter(textma);
            }
        }
    }));
    Widget.push_back(new Textbox(230,300,50,25,textma,1,255,0,0,true));
    while(gin >> ev && ev.keycode != key_escape)
    {
        gout << move_to(0,0) << color(0,0,0) << box(SX,SY);
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
        Widget[i] -> functionmake(ev);
        Widget[i] -> focus(ev,i);
        Widget[i] -> draw();
        }

        gout << refresh;


    }
}
