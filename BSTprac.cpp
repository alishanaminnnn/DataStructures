
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

Node *insert(Node *r, int data) {
  if (r == nullptr) {
    return new Node(data);
  }
  if (data > r->data) {
    r->right = insert(r->right, data);
  }
  if (data < r->data) {
    r->left = insert(r->left, data);
  }
  return r;
}

bool isBST(Node *r, int min, int max) {

  if (r == nullptr) {
    return true;
  }

  if (r->data <= min || r->data >= max) {
    return false;
  }

  return isBST(r->left, min, r->data) && isBST(r->right, r->data, max);
}

int maximum(Node *r) {
  if (r == nullptr) {
    return -1;
  }
  if (r->right==nullptr) {
    return r->data;
  } 
  return maximum(r->right);
}


int main() {

  Node *root = new Node(10);

  root->left = new Node(5);
  root->right = new Node(13);
  root->left->left = new Node(3);
  root->right->right = new Node(15);

  return 0;
}
