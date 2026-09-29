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
    int arr[]={2,4,6,7,2,4};
    Stack s1;
    for (int i = 0; i < 6; i++)
    {
        s1.push(*(arr+i));
    }
    cout<<"Reversed Array: ";
    for (int i = 0; i < 6; i++)
    {
        cout<<s1.peek()<<" ";
        s1.pop();
    }
    
    
    

    return 0;
}