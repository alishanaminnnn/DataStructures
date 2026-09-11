#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkList
{
public:
    Node *head;
    Node *current;
    int lenght;

public:
    LinkList()
    {
        head = nullptr;
        current = nullptr;
        lenght = 0;
    }
    void createLinkList(int value)
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
            head->prev = temp;
            head = temp;
        }
        lenght++;
    }
    void start()
    {
        current = head;
    }
    void tail()
    {
        start();
        while (current->next != nullptr)
        {
            current = current->next;
        }
    }
    void display()
    {
        start();
        cout << "List: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void insert(int value, int position)
    {
        start();
        Node *temp;
        temp = new Node(value);
        if (position == 1)
        {
            current->prev = temp;
            temp->next=current;
            head=temp;
        }
        else if (position == lenght+1)
        {
            tail();
            current->next = temp;
            temp->prev = current;
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                current = current->next;
            }
            temp->prev=current;
            temp->next = current->next;
            current->next->prev = temp;
            current->next = temp;
        }
        lenght++;
    }
    void remove(int position)
    {
        start();
        for (int i = 1; i < position; i++)
        {
            current = current->next;
        }

        if (position == 1)
        {
            head = current->next;
            head->prev = nullptr;
            delete current;
        }
        else
        {
            current->prev->next = current->next;

            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }

            delete current;
        }

        lenght--;
    }
};
int main()
{
    LinkList l1;
    l1.createLinkList(3);
    l1.createLinkList(5);
    l1.createLinkList(7);
    l1.createLinkList(9);
    l1.remove(2);
    l1.insert(10,2);
    l1.display();
    return 0;
}
