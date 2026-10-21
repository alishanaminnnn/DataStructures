#include <iostream>
using namespace std;

class ListStack {
public:
  struct Node {
    char data;
    Node *next;
    Node(char value) {
      data = value;
      next = nullptr;
    }
  };
  Node *head;
  Node *curr;
  ListStack() { head = curr = nullptr; }
  bool IsEmpty() { return head == nullptr; }
  void push(char value) {
    if (IsEmpty()) {
      head = new Node(value);
    } else {
      Node *temp = new Node(value);
      temp->next = head;
      head = temp;
    }
  }
  char pop() {
    if (IsEmpty()) {
      return -1;
    } else {
      Node *temp = head;
      char value = temp->data;
      head = head->next;
      delete temp;
      return value;
    }
  }
  char peek() {
    char value = head->data;
    return value;
  }
};

int main() {
  ListStack l1;

  return 0;
}