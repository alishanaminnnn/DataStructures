#include<iostream>
using namespace std;

class Queue{
    private:
    struct Node{
        int Data;
        Node * next;
        Node(int value){
            Data=value;
            next=nullptr;
        }
    };
    int size=0;
    Node *front;
    Node *rear;
    bool isEmpty(){return size==0;}

    public:
    Queue(){//default constructor
        front=nullptr;
        rear=nullptr;
    }
    Queue(int value){//paramatrized constructor
        Node*temp=new Node(value);
        front=rear=temp;
    }
    void enqueue(int value){
        Node *temp=new Node(value);
        if(isEmpty()){
            rear=front=temp;
        }
        else{
            rear->next=temp;
        }
        size++;
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        else{
            int temp;
            Node* removal;
            temp=front->Data;
            removal=front;
            front=front->next
        }
    }
};


int main(){



    return 0;
}