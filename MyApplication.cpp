#include "MyApplication.hpp"

void MyApplication::make(string a)
{
    selected.push_back(a);
}

void MyApplication::writeout()
{
    ofstream myapplicationValue;
    myapplicationValue.open ("myapplicationValue.txt");
    for (unsigned int i = 0; i < selected.size(); i++)
    {
        myapplicationValue << selected[i] << "\n";
    }
    myapplicationValue.close();
}
void MyApplication::clearvecktor()
{
    selected.clear();
}
