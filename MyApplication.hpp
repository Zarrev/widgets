#ifndef MYAPPLICATION_HPP_INCLUDED
#define MYAPPLICATION_HPP_INCLUDED
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class MyApplication
{
protected:

    vector<string> selected;
    bool thank = false;

public:

    virtual void make(string a);
    virtual void writeout();
    virtual void clearvecktor();
};


#endif // MYAPPLICATION_HPP_INCLUDED
