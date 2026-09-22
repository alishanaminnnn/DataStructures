#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *arr;
    int *curr;
    int lenght;
    int capacity;

public:
    ArrayList(int c)
    {
        arr = new int[c];
        curr = nullptr;
        lenght = 0;
        capacity = c;
    }
    void back()
    {
        curr--;
    }
    void next()
    {
        curr++;
    }
    void start()
    {
        curr = arr;
    }
    void tail()
    {
        start();
        if (lenght == 0)
        {
            curr = arr;
        }
        else
        {
            curr = curr + lenght - 1;
        }
    }
    void insert(int position, int value)
    {
        if (position > capacity || position < 1)
        {
            cout << "Invalid Position";
        }
        else if (lenght == capacity)
        {
            cout << "Array is Full!";
        }
        else
        {
            tail();
            curr = curr + 1;
            for (int i = lenght; i >= position; i--)
            {
                *(curr) = *(curr - 1);
                back();
            }
            start();
            *(curr + position - 1) = value;
        }
        lenght++;
    }
    void remove(int position)
    {
        if (position < 1 || position > lenght)
        {
            cout << "Invalid Position";
        }
        else
        {
            start();
            curr = curr + position - 1;
            for (int i = lenght; i >= position; i--)
            {
                *curr = *(curr + 1);
                next();
            }
            lenght--;
        }
    }
    void display()
    {
        start();
        cout << "Array: ";
        for (int i = 0; i < lenght; i++)
        {
            cout << *(arr + i) << " ";
        }
    }
    int getLenght()
    {
        return lenght;
    }

    void reverse()
    {
        start();
        for (int i = 0; i < lenght/2; i++)
        {
            int temp=*(arr+i);
            *(arr+i)=*(arr+lenght-i-1);
            *(arr+lenght-i-1)=temp;
        }
    }
};

int main()
{
    ArrayList A1(10);
    A1.insert(1, 2);
    A1.insert(2, 4);
    A1.insert(3, 6);
    A1.insert(4, 8);
    A1.insert(5, 3);
    A1.insert(6, 5);
    A1.insert(7, 7);
    A1.insert(8, 9);
    A1.insert(2, 10);
    A1.remove(3);
    A1.display();
    A1.reverse();
    A1.display();


    return 0;
}
