#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkList
{
public:
    Node *head;
    Node *current;
    Node *end;
    int lenght;

public:
    LinkList()
    {
        head = nullptr;
        current = nullptr;
        end = nullptr;
        lenght = 0;
    }

    void createLinkList(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);

            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *temp;
            temp = new Node(value);

            tail();

            temp->next = head;
            temp->prev = current;

            current->next = temp;
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

        while (current->next != head)
        {
            current = current->next;
        }
    }

    void insert(int value, int position)
    {
        Node *temp;
        temp = new Node(value);

        if (position == lenght + 1)
        {
            tail();

            temp->prev = current;
            temp->next = head;

            current->next = temp;
            head->prev = temp;
        }
        else if (position == 1)
        {
            tail();

            temp->prev = current;
            temp->next = head;

            current->next = temp;
            head->prev = temp;

            head = temp;
        }
        else
        {
            start();

            for (int i = 1; i < position - 1; i++)
            {
                current = current->next;
            }

            temp->next = current->next;
            temp->prev = current;

            current->next = temp;
            temp->next->prev = temp;
        }

        lenght++;
    }

    void display()
    {
        start();

        cout << "List: ";

        for (int i = 0; i < lenght; i++)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void remove(int position)
    {
        start();

        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        if (lenght == 1)
        {
            delete current;
            head = nullptr;
            current = nullptr;
            lenght--;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head)
        {
            head = current->next;
        }

        delete current;
        current = nullptr;

        lenght--;
    }
};

int main()
{
    LinkList l1;

    l1.createLinkList(2);
    l1.createLinkList(3);
    l1.createLinkList(4);
    l1.createLinkList(5);
    l1.createLinkList(6);
    l1.createLinkList(7);
    l1.remove(3);
    l1.display();
    l1.insert(9, 7);

    l1.display();

    return 0;
}