
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
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    int temp = minimum(root->right);
    root->data = temp;
    root->right = remove(root->right, temp);
  }

  return root;
}

int main() {
  Node *root = nullptr;

  root = insert(root, 1);
  root = insert(root, 10);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 1);
  root = insert(root, 5);
  root = insert(root, 0);

  cout << "Inorder traversal: ";
  inOrder(root);

  cout << "\n";

  return 0;
}
