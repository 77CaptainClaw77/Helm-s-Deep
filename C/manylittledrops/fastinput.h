#ifndef FASTINPUT_H_INCLUDED
#define FASTINPUT_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <bits/c++io.h>
using namespace std;
void fastip(int& num)
{
    bool neg=false;
    num=0;
    register int c;
    c=getchar();
    if(c=='-')
    {
        neg=true;
        c=getchar();
    }
    for(;c>47 && c<58;c=getchar())
        num=(num<<3)+(num<<1)+c-48;
    if(neg)
        num*=-1;
}


#endif // FASTINPUT_H_INCLUDED
