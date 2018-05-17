#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED
#include<iostream>
#include <stdlib.h>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<map>
using namespace std;

class srch{

public:
    map<string,int>m;
    map<string,int>::iterator it;
void seach(string songname,int songid,int Size){
m.insert(pair<string,int>(songname,songid));
if(m.size()==Size){
string op;
cout<<"enter the name of song:";
cin>>op;
for(it=m.begin();it!=m.end();it++){
    if(op==it->first){
	        cout<<it->first<<it->second;

	}
}
}
}
};


#endif // SEARCHING_H_INCLUDED
