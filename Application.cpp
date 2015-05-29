#include "graphics.hpp"
#include "Application.hpp"
#include "orginalwidget.hpp"
#include "CheckBox.hpp"
#include "textbox.hpp"
#include "Counter.hpp"
#include "Counter2.hpp"
#include "Select.hpp"
#include "Button.hpp"
#include "Choose.hpp"
#include "MyApplication.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Application::Application(int _SX, int _SY) : SX(_SX), SY(_SY) {}

void Application::run()
{
    gout.open(SX,SY);
    event ev;
    gin.timer(20);

    MyApplication MA;
    bool zero = false;
    vector<Originalwidget*> Widget;
    Widget.push_back(new Textbox(20,20,100,25,"Ez egy StaticTextBox",0,255,0,0,true));
    Widget.push_back(new Counter(20,50,100,25,"0",1,20,20,20,100,-5));
    Widget.push_back(new Textbox(20,80,100,25,"--",2,150,150,150,false));
    Widget.push_back(new Select(20,170,100,50,"--",3,0,0,0));
    Widget.push_back(new Button(20,110,100,25,"+",4,600,600,1000,"+++",[&](){    }));
    Widget.push_back(new CheckBox(20,140,25,25,5,255,0,0));
    Widget.push_back(new CheckBox(50,140,25,25,6,0,255,0));
    Widget.push_back(new Counter2(20,250,100,25,"0",7,20,20,20,22,2));
    Widget.push_back(new Textbox(250,250,50,25,"--",8,255,0,0,true));
    Widget.push_back(new Button(130,250,50,25,"+",9,600,600,1000,"++",[&]()
    {
        Widget[7] -> isetter();
    }));
    Widget.push_back(new Button(190,250,50,25,"-",10,600,600,1000,"--",[&]()
    {
        Widget[7]-> isetter2();
    }));
    Widget.push_back(new Choose(300,50,100, 300, 5, 100, 11, 255, 0, 200));
    Widget.push_back(new Textbox(410,50,100,25,"--",12,150,150,150,false));
    Widget.push_back(new Button(410,80,50,25,"ADD",13,600,600,1000,"ADDED",[&]()
    {
        Widget[12] -> ssetter();
        Widget[12] -> functionmake(ev);
        if (Widget[12] -> getter().size() != 0)
        {
            Widget[11] -> ssetter3(Widget[12] -> getter());
        }
    }));
    Widget.push_back(new Button(410,110,50,25,"DEL",14,600,600,1000,":(",[&]()
    {
        Widget[11] -> functionmake(ev);
        if (Widget[11]->getter().size() != 0)
        {
            Widget[11]->ssetter();
            Widget[12]->ssetter3(Widget[11]->getter());
        }
        Widget[11] -> functionmake(ev);
    }));
Widget.push_back(new Button(SX*2/3,250,50,25,"Write",15,600,600,1000,"Check",[&]()
    {
        MA.clearvecktor();
        zero = true;
    }));

    ///   */
    while(gin >> ev && ev.keycode != key_escape)
    {
        gout << move_to(0,0) << color(0,0,0) << box(SX,SY);
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
        Widget[i] -> focus(ev,i);
        Widget[i] -> functionmake(ev);
        Widget[i] -> draw();
        }
        Widget[8] -> ssetter2(Widget[7] -> sgetter("Counter2"));
if (zero)
    {
        for (unsigned int j = 0; j < Widget.size(); j++)
        {

            MA.make(Widget[j]->resultgetter());
        }
        zero = false;
        MA.writeout();
    }
        gout << refresh;
    }

}
