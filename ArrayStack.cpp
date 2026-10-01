#include<iostream>
using namespace std;


class ArrayStack{
    public:
    int *arr;
    int size;
    int capacity;

    public:
    bool isEmpty(){ return (size==0);}
    bool isFull(){return (size==capacity);}
    ArrayStack(){
        capacity=10;
        arr=new int[capacity];
        size=0;
    }
    ArrayStack(int value){
        capacity=10;
        arr=new int[capacity];
        *arr=0;
        size=1;
    }
    void push(int value){
        if (isFull())
        {
            cout<<"The stack is Overflowed";
        }
        else
        {
        *(arr+size)=value;
        size++;
        }
    }
    void pop(){
        
    }
};



int main(){


    return 0;
}