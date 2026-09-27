#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (capacity == top + 1)
        {
            return true;
        }
        return false;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overFlow";
        }
        else
        {
            top++;
            *(arr + top) = value;
        }
    }
    int pop(){
        if (isEmpty())
        {
            cout<<"underFlow";
            return -1;
        }
        else
        {
            int temp=*(arr+top);
            top--;
            return temp;
        }
    }
    int peak(){
        return *(arr+top);
    }
    ~Stack(){
        delete[] arr;
    }
};
int main(){
    Stack s1(5);
    cout<<"The Stack is Empty: "<<s1.isEmpty()<<endl;
    s1.push(2);
    s1.push(3);
    s1.push(6);
    cout<<"The top element is: "<<s1.peak()<<endl;
    cout<<"The popped element is: "<<s1.pop()<<endl;
    cout<<"The top element is: "<<s1.peak()<<endl;



    return 0;
}
