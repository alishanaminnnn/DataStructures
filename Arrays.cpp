#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr;
    int* current;
    int capacity;
    int length;
    
public:
    ArrayList(int size) {
        arr = new int[size];
        capacity = size;
        current = nullptr;
        length = 0;
    }

    ~ArrayList() {
        delete[] arr;
    }

    void start() {
        current = arr;
    }

    void next() {
        current++;
    }

    void back() {
        current--;
    }

    void tail() {
        if (length == 0) {
            current = arr;
        } else {
            current = arr + length - 1;
        }
    }

    void insert(int value, int position) {
        // Positions are 1-based: 1 is the first position
        if (length == capacity) {
            cout << "Array is full.\n";
            return;
        }

        if (position < 1 || position > length + 1) {
            cout << "Invalid position.\n";
            return;
        }

        // Point to the first unused position.
        current = arr + length;

        // Shift elements one position to the right.
        for (int i = length; i >= position; i--) {
            *current = *(current - 1);
            back();
        }

        *current = value;
        length++;
    }

    void display() {
        cout << "Array: ";

        for (int i = 0; i < length; i++) {
            cout << *(arr + i) << " ";
        }

        cout << '\n';
    }
};

int main() {
    ArrayList a1(6);

    a1.insert(22, 1);
    a1.insert(3, 2);
    a1.insert(10, 2);

    a1.display();  // Array: 22 10 3

    return 0;
}