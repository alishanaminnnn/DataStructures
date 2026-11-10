
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

int maximum(Node *r) {
  if (r == nullptr) {
    return -1;
  }
  if (r->right == nullptr) {
    return r->data;
  }
  return maximum(r->right);
}

int manimum(Node *r) {
  if (r == nullptr) {
    return -1;
  }
  if (r->left == nullptr) {
    return r->data;
  }
  return maximum(r->left);
}

bool isBSt(Node *r, int max, int min) {
  if (r == nullptr) {
    return true;
  }

  if (r->data >= max) {
    return false;
  }

  if (r->data <= min) {
    return false;
  }

  return isBSt(r->right, max, r->data) && isBSt(r->left, r->data, min);
}

int minDistance(Node *r){
  if(r==nullptr){
    return 0;
  }
  x=minDistance()
}

int main() {

  Node *root = new Node(10);

  root->left = new Node(5);
  root->right = new Node(13);
  root->left->left = new Node(3);
  root->right->right = new Node(15);

  return 0;
}
