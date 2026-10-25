#include <iostream>
#include <queue>
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

void insert(Node *root, int val) {
  if (root == NULL) {
    root = new Node(val);
    return;
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();

    if (curr->left == NULL) {
      curr->left = new Node(val);
      return;
    } else {
      q.push(curr->left);
    }

    if (curr->right == NULL) {
      curr->right = new Node(val);
      return;
    } else {
      q.push(curr->right);
    }
  }
}

int main() { 
  Node* root=new Node(20);
  insert(root,30);
  
  return 0; }