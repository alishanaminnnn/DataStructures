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
    void push(int val){
        Node *temp=new Node(val);
        temp->next=top; 
        top=temp;
        size++;
    }
    void pop(){
        if (top==nullptr)
        {
           cout<<"UnderFlow";
        }
        else{
        Node *temp=top;
        top=top->next;
        delete top;
        }
    }
    

        
    };