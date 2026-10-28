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

void preOrder(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << "  ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root) {
  if (root == nullptr) {
    return;
  }
  preOrder(root->left);
  cout << root->data << "  ";
  preOrder(root->right);
}

void postOrder(Node *root) {
  if (root == nullptr) {
    return;
  }
  preOrder(root->left);
  preOrder(root->right);
  cout << root->data << "  ";
}

Node *parent(Node *curr, Node *p, Node *par) {
  if (curr == nullptr) {
    return nullptr;
  }

  if (curr == p) {
    return par;
  }
  Node *t = nullptr;
  t = parent(curr->left, p, curr);
  if (t != nullptr) {
    return t;
  } else {
    t = parent(curr->right, p, curr);
    return t;
  }
}
int height(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  int x = height(root->left);
  int y = height(root->right);

  if (x > y) {
    return x + 1;
  } else {
    return y + 1;
  }
}

node* sibling(node* root, node* p)
{
    node* par = parent(root, p, nullptr);

    if (par == nullptr)
        return nullptr;

    if (par->left == p)
        return par->right;
    else
        return par->left;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(5);
  preOrder(root);

  return 0;
}