#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val):data(val),next(nullptr){}
};

class LinkListStack{
    public:
    Node* top;
    int size;
    public:
    LinkListStack(){
        top=nullptr;
        size=0;
    }
    void push(int val)

        
    };