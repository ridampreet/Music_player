#include<iostream>
#include<string.h>
#include"shuffle.h"
#include"searching.h"
using namespace std;
struct node{
int songid;
string songname,artistname;
node *next,*prev;

};

class songs{
private:
        int id,visited[100];
        node *head,*tail;
        char ch,choice;

public:
    songs(){
    id=-1;
    head=NULL;
    tail=NULL;
    ch='\0';
    }
    void initialize(int n)//to initialize the visited array that will be use in the shuffle function
    {
        visited[n];
        for(int i=0;i<n;i++){
            visited[i]=0;

        }


    }


    struct node *create(string data,string artist){
        node *nn;
        nn=new node;
        nn->songname=data;
        nn->artistname=artist;
        nn->next=NULL;
        nn->prev=NULL;
        nn->songid=++id;
    if(head==NULL){
        head=nn;
        head->prev=NULL;
        tail=head;
    }else{
    tail->next=nn;
    nn->prev=tail;
    tail=nn;
    }
    };
    struct node *print(){
int x;
    node *ptr;
    cout<<"To play songs in shuffle enter 'h'|||||| else just hit any key"<<endl<<"To continue press any key"<<"          "<<"To search a song enter 'f'"<<endl;
    cin>>choice;
    if(choice=='f'){
        sendtohash();
    }

    else if(choice=='h'){
        shuf sh;//creating object of class shuffle for generation of a random number
        //generate random by passing tails id which represents the number of songs
    int num=tail->songid+1;
    int p=tail->songid+1;
    ptr=head;

    while(num--)
    {

    x=sh.gen(tail->songid);
    while(visited[x]==1){
    x=sh.gen(p);
    }
    cout<<x<<" ";
    ptr=head;

    while(ptr!=NULL)
{
    visited[x]=1;
    if(ptr->songid==x){
    cout<<ptr->songname<<endl;
    break;
            }
    ptr=ptr->next;

}
            }
    }
    else if(choice!='h'){
{
        ptr=head;
        cout<<"To go on previous enter 'p' to go on next song enter 'n'"<<endl;
    while(ptr!=NULL)
{

            cout<<"Name of the song: "<<ptr->songname<<" "<<"id of song: "<<ptr->songid<<endl;
            cin>>ch;

if(ch=='n')
{
        ptr=ptr->next;
}
else if(ch=='p')
{
        ptr=ptr->prev;
}

}
}
}
    }


struct node *del(){
string input;
cin>>input;
node *ptr;
ptr=head;
while(ptr!=NULL)
{
    if(ptr->songname==input)
{
            cout<<"DELETED SONG: "<<input<<endl;
            if(head==tail){
                head=NULL;
                tail=NULL;
            }
    else if(ptr->prev==NULL)
    {
            head=ptr->next;
            head->prev=NULL;
            delete(ptr);
    }
    else if(ptr==tail){
    ptr->prev->next=NULL;
    tail=ptr;
    delete(ptr);
                            }

    else{
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    delete(ptr);
        }
}
    ptr=ptr->next;
}

};

void sendtohash(){
srch a;
node *t=head;
while(t!=NULL){
    a.seach(t->songname,t->songid,tail->songid+1);
    t=t->next;
}
}

};
int main()
{

    srch a;//object for search implementation

    songs s;

    int n;
    string data,artistname;
    cout<<"WELCOME TO THE MUSIC PLAYER "<<endl;
    cout<<"ENTER THE NUMBER OF SONGS YOU WANT TO ADD:"<<endl;
    cin>>n;
    s.initialize(n);
    while(n--){

        cout<<"Name:";
        cin>>data;
        cout<<"Artist name:";
        cin>>artistname;
        s.create(data,artistname);
    }

char ch;
string naam;
cout<<"To play the songs enter 'o':"<<endl<<"To delete enter 'd'"<<endl;
cin>>ch;

if(ch=='o'){
     s.print();}
else if(ch=='d'){
    s.del();
}



    return 0;
}
