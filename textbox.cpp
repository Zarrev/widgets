    #include "textbox.hpp"

    Textbox::Textbox(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b, bool _statictextbox)
   : Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
   {
        statictextbox = _statictextbox;
   }

    void Textbox::draw()
    {
        if (!statictextbox)
        {
            gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << move_to(posx+margin,posy+sizey/2+gout.cascent()/2) << color(255-r,255-g,255-b) << text(textmess);
        }
        else
        {
            gout << move_to(posx,posy) << color(r,g,b) << box(10+gout.twidth(textmess),sizey) << move_to(posx+margin,posy+sizey/2+gout.cascent()/2) << color(255-r,255-g,255-b) << text(textmess);
        }
  }

    void Textbox::functionmake(event ev)
    {
        if (statictextbox)
        {
            focusban = false;
        }
        if (focusban)
        {
            if (counter == 0){
            textmess = "";
            counter++;}
            if (ev.keycode>=32 && ev.keycode<255 && number < (sizex-15))
            {
                textmess+=ev.keycode;
            }
            else if (ev.keycode == 8 && textmess != "")
            {
                string seged = textmess;
                textmess = "";
                for (unsigned int i = 0; i<seged.length()-1;i++)
                {
                    textmess += seged[i];
                }
            }
            number = gout.twidth(textmess);
            /*if (ev.keycode == key_enter)
            {
                stringtext.push_back(textmess);
                textmess = "";
            }*/
        }
        if (logical && textmess != "")
        {
            if (textmess != "--"){
            stringtext.push_back(textmess);}
            textmess = "--";
            logical = false;
            counter = 0;
        }
        if (logical && textmess == "")
        {
            counter = 0;
            textmess = "--";
        }
        /*if (!focusban && !statictextbox)
        {
            counter = 0;
            textmess = "--";
        }*/
        result = textmess;
    }

    string Textbox::sgetter(string a)
    {
            return textmess;

    }
    void Textbox::ssetter()
    {
        logical = true;
    }
    bool Textbox::booler()
    {

    }
    void Textbox::ssetter3(vector<string> a)
    {
        stringtext = a;
    }
    void Textbox::ssetter2(string a)
    {
            textmess = a;
    }

