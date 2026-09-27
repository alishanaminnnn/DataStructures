#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val) : data(val), next(nullptr) {}
};

class LinkListStack
{
public:
    Node *top;
    int size;

public:
    LinkListStack()
    {
        top = nullptr;
        size = 0;
    }
    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
        size++;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "UnderFlow";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }
    int peek()
    {
        if (top == nullptr)
        {
            return -1;
            cout << "Stack is empty";
        }
        else
        {
            return top->data;
        }
    }
    
    ~LinkListStack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    LinkListStack l1;
    l1.push(5);
    l1.push(6);
    cout << l1.peek();
    l1.pop();
    cout << l1.peek();

    return 0;
}