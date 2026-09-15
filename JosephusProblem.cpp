#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkList
{
public:
    int lenght;
    Node *head;
    Node *curr;

    LinkList()
    {
        lenght = 0;
        head = nullptr;
        curr = nullptr;
    }

    void createList(int value)
    {
        Node *temp = new Node(value);

        if (head == nullptr)
        {
            head = temp;
            head->next = head;
        }
        else
        {
            tail();            // find last node
            temp->next = head; // new node points to old head
            curr->next = temp; // last node points to new node
            head = temp;       // new node becomes head
        }

        lenght++;
    }

    void display()
    {
        start();
        cout << "Linked List: ";

        while (curr->next != head )
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void start()
    {
        curr = head;
    }

    void tail()
    {
        start();

        for (int i = 0; i < lenght - 1; i++)
        {
            curr = curr->next;
        }
    }

    void insertion(int value, int position)
    {
        if (position < 1 || position > lenght + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 1)
        {
            Node *temp;
            temp = new Node(value);
            temp->next = head;
            head = temp;
            lenght++;
        }

        else if (position == lenght + 1)
        {
            Node *temp;
            temp = new Node(value);
            tail();
            curr->next = temp;
            lenght++;
        }

        else
        {
            start();

            Node *temp;
            temp = new Node(value);

            for (int i = 0; i < position - 2; i++)
            {
                curr = curr->next;
            }

            temp->next = curr->next;
            curr->next = temp;
            lenght++;
        }
    }
    void remove(int index)
    {
        Node *removal;
        if (index == 0)
        {
            tail();
            head->next = head;
            Node *removal = curr->next;
            curr->next = removal->next;
            delete removal;
        }
        else
        {
            start();
            for (int i = 0; i < lenght - 2; i++)
            {
                curr = curr->next;
            }
            Node *removal = curr->next;
            curr->next = removal->next;
            delete removal;
        }
        lenght--;
    }

    int josephus(int nodes, int skips)
    {
        if (nodes <= 0 || skips <= 0)
            return -1;

        start();

        while (lenght > 1)
        {

            for (int i = 1; i < skips; i++)
            {
                curr = curr->next;
            }

            Node *removal = curr->next;

            if (removal == head)
                head = head->next;

            curr->next = removal->next;

            delete removal;
            lenght--;

            curr = curr->next;
        }

        return head->data;
    }
};

int main()
{
    LinkList l1;

    l1.createList(3);
    l1.createList(12);
    l1.createList(8);
    l1.createList(4);
    l1.createList(34);

    l1.display();

    return 0;
}