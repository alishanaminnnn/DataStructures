#include <iostream>
using namespace std;

class Node {
public:
  int key;
  int size;
  Node *left;
  Node *right;

  Node(int k) {
    key = k;
    size = 1;
    left = right = nullptr;
  }
};

class b_search_tree {
public:
  Node *root = nullptr;

  void insertion(int k, Node *&root) {
    if (root == nullptr) {
      root = new Node(k);
      return;
    }

    if (k > root->key) {
      insertion(k, root->right);
    } else {
      insertion(k, root->left);
    }

    root->size = 1;

    if (root->left != nullptr) {
      root->size += root->left->size;
    }

    if (root->right != nullptr) {
      root->size += root->right->size;
    }
  }

  void preOrder(Node *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->key << ":"<<root->size<<" ";
    preOrder(root->left);
    preOrder(root->right);
  }
};

void generateKeys(int R, int keys[], int n) {
  int s = R + 1;
  int count = 0;
  while (count < n) {
    s = (s * 7) % 10007;
    int k = 10 + s % 90;
    bool used = false;
    for (int j = 0; j < count; j++)
      if (keys[j] == k)
        used = true;
    if (!used)
      keys[count++] = k;
  }
}

int main() {
  int roll_no = 48;
  int n = 13;
  int keys[n] = {};
  b_search_tree tree;
  generateKeys(roll_no, keys, n);
  for (int i = 0; i < n; i++) {
    tree.insertion(keys[i], tree.root);
  }

  cout << "PreOrder :";
  tree.preOrder(tree.root);

  return 0;
}