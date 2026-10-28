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

Node *insert(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }

  if (value > root->data) {
    root->right = insert(root->right, value);
  } else {
    root->left = insert(root->left, value);
  }

  return root;
}

void inOrder(Node *root) {
  if (root == nullptr) {
    return;
  }
  inOrder(root->left);
  cout << root->data << "  ";
  inOrder(root->right);
}

bool search(Node *root, int e) {
  if (root == nullptr) {
    return false;
  }
  if (root->data == e) {
    return true;
  }
  if (e > root->data) {
    return search(root->right, e);
  } else {
    return search(root->left, e);
  }
}

int minimum(Node *root) {
  if (root == nullptr) {
    return -1;
  }

  if (root->left == nullptr) {
    return root->data;
  }

  return minimum(root->left);
}

Node *remove(Node *root, int value) {
  if (root == nullptr) {
    return nullptr;
  }

  if (value < root->data) {
    root->left = remove(root->left, value);
  } else if (value > root->data) {
    root->right = remove(root->right, value);
  } else {
    // Case 1 and Case 2: zero or one child
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // Case 3: two children
    Node *temp = minimumNode(root->right);
    root->data = temp->data;
    root->right = remove(root->right, temp->data);
  }

  return root;
}

int main() {
  Node *root = new Node(1);
  insert(root, 10);
  insert(root, 3);
  insert(root, 7);
  insert(root, 1);
  insert(root, 5);
  insert(root, 0);
  inOrder(root);

  return 0;
}