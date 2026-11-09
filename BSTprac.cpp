
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = right = nullptr;
  }
};

bool isEmpty(Node *r) { return r == nullptr; }

bool searchNode(Node *r, int data) {

  if (r == nullptr) {
    return false;
  }
  if (r->data == data) {
    return true;
  }
  if (data > r->data) {
    searchNode(r->right, data);
  } else {
    searchNode(r->left, data);
  }
}

void insert(Node *r, int data){
    if(r==nullptr){
        return;
    }
    if(data> r->data){
        insert(r->)
    }
}
int main() {

  Node *root = new Node(10);

  root->left = new Node(5);
  root->right = new Node(13);
  root->left->left = new Node(3);
  root->right->right = new Node(15);

  return 0;
}
