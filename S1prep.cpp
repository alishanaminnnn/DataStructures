#include<iostream>
using namespace std;

class ArrayList{
    private:
    int* arr;
    int* curr;
    int lenght;
    int capacity;

    public:
    ArrayList(int c){
        arr=new int[c];
        curr=nullptr;
        lenght=0;
        capacity=c;
    }
    void back(){
        curr--;
    }
    void next(){
        curr++;
    }
    void start(){
        curr=arr;
    }
    void tail(){
        start();
        if (lenght==0)
        {
            curr=arr;
        }
        else
        {
            curr=curr+lenght-1;
        }
    }
    void insert(int position,int value){
        if(position>capacity || position<1){
            cout<<"Invalid Position";
        }
        else if (lenght==capacity)
        {
            cout<<"Array is Full!";
        }
        else
        {
            start();
            for ( int i = 0; i < position-1; i++)
            {
                next();
            }

            
        }
        
        
    }

};

