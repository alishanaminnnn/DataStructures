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
    };
    bool isEmpty(){return size==0;}
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
        rear->next=temp;
        rear=temp;
        size++;
        }
    }
    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        else if (size>1){
            int temp=front->data;
            Node* removal=front;
            front=front->next;
            delete removal;
            size--;
            return temp;
            
        }
        else{
            rear=front=nullptr;
        }


    }
    int peek(){
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }



    
};
int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1.dequeue();

    return 0;
}