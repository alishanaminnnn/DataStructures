#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *curr;
    Node *head;
    int lenght;

public:
    LinkedList()
    {
        curr = nullptr;
        head = nullptr;
        lenght = 0;
    }
    void createList(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
        }
        else
        {
            Node *temp;
            temp = new Node(value);
            temp->next = head;
            head = temp;
        }
        lenght++;
    }

    void insert(int index, int value)
    {
        Node *temp = new Node(value);

        if (index == 0)
        {
            temp->next = head;
            head = temp;
        }
        else if (index == lenght)
        {
            tail();
            curr->next = temp;
        }
        else
        {
            start();

            for (int i = 0; i < index - 1; i++)
            {
                curr = curr->next;
            }

            temp->next = curr->next;
            curr->next = temp;
        }

        lenght++;
    }
    void start()
    {
        curr = head;
    }
    void tail()
    {
        start();
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
    }
    void display()
    {
        start();
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};
int main()
{
    LinkedList l1;
    l1.createList(23);
    l1.createList(3);
    l1.createList(33);
    l1.createList(4);
    l1.insert(3, 2);
    l1.display();

    return 0;
}