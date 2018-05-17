#ifndef SHUFFLE_H_INCLUDED
#define SHUFFLE_H_INCLUDED
#include<iostream>
#include <stdlib.h>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class shuf{

public:
    shuf()
    {
        srand(time(0));
    }
int gen(int no){
    no=no++;
int v=rand() %no;//mod by number of songs

return v;
    }
};

#endif // SHUFFLE_H_INCLUDED
