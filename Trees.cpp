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

void preOrder(Node *n) {
  if (n == nullptr) {
    return;
  }
  cout << n->data << "\t";
  preOrder(n->left);
  preOrder(n->right);
}

void InOrder(Node *n) {
  if (n == nullptr) {
    return;
  }
  InOrder(n->left);
  cout << n->data << "\t";
  InOrder(n->right);
}

void postOrder(Node *n) {
  if (n == nullptr) {
    return;
  }
  InOrder(n->left);
  InOrder(n->right);
  cout << n->data << "\t";
}

node *parent(node *curr, node *p, node *par) {
  if (curr == nullptr) {
    return nullptr;
  }
  if (curr == p) {
    return par;
  }
  node *t = nullptr;
  t = parent(curr->left, p, curr) if (t != nullptr) { return t; }
  else {
    t = parent(curr->right, p, curr);
    return t;
  }
}

int main() {
  Node *root = new Node(12);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(6);
  root->left->right = new Node(7);
  root->right->left = new Node(3);

  return 0;
}