#include<iostream>
using namespace std;

class Queue{
    private:
    struct Node{
        int data;
        Node *next;
        Node(int value){
            data=value;
            next=nullptr;
        }
    bool isEmpty(){return size==0}
    int size;
    Node* front;
    Node* rear;
    //default constructor
    public:
    Queue(){
        size=0;
        front=nullptr;
        rear=nullptr;
    }
    Queue(int value){
        front=new Node(value);
        rear=front;
        size=1;
    }
    void enqueue(int value){
        Node *temp=new Node(value);
        if(isEmpty()){
            front=temp;
            rear=temp;
            size=1;
        }
        else{
        tail->next=temp;
        tail=temp;
        size++;
        }
    }



    }
};