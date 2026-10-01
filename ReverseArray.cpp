#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    public:
    Node(int value):data(value),next(nullptr){}
};

class Stack{
    Node* top;
    int size=0;
    public:
    void push(int value){
        Node* temp=new Node(value);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        if (size==0)
        {
            cout<<"Stack underflow\n";
        }
        else
        {
        Node *temp=top;
        top=top->next;
        delete temp;
        size--;
        }  
    }

    int peek(){
        if (top==nullptr)
        {
            return -1;
        }
        else
        {
            return top->data;
        }

    }
};


int main(){
    Stack s1;

    
    

    return 0;
}

