#include <iostream>
using namespace std;

struct BinarySearchTree {
private:
  struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
      data = value;
      left = nullptr;
      right = nullptr;
    }
  };

  Node *root;

  void insert(Node *&curr, int value) {
    if (curr == nullptr) {
      curr = new Node(value);
      return;
    }

    if (value < curr->data) {
      insert(curr->left, value);
    } else {
      insert(curr->right, value);
    }
  }

  void preorder(Node *curr) {
    if (curr == nullptr) return;
    cout << curr->data << " ";
    preorder(curr->left);
    preorder(curr->right);
  }

  void inorder(Node *curr) {
    if (curr == nullptr) return;
    inorder(curr->left);
    cout << curr->data << " ";
    inorder(curr->right);
  }

  void postorder(Node *curr) {
    if (curr == nullptr) return;
    postorder(curr->left);
    postorder(curr->right);
    cout << curr->data << " ";
  }

  bool search(Node *curr, int value) {
    if (curr == nullptr) return false;
    if (value == curr->data) return true;

    if (value < curr->data) {
      return search(curr->left, value);
    } else {
      return search(curr->right, value);
    }
  }

  void destroy(Node *curr) {
    if (curr == nullptr) return;
    destroy(curr->left);
    destroy(curr->right);
    delete curr;
  }

  bool insertChild(int parentValue, int value, bool isLeft) {
    Node *curr = root;
    int lo = 0, hi = 0;
    bool hasLo = false, hasHi = false;

    while (curr != nullptr && curr->data != parentValue) {
      if (parentValue < curr->data) {
        hi = curr->data;
        hasHi = true;
        curr = curr->left;
      } else {
        lo = curr->data;
        hasLo = true;
        curr = curr->right;
      }
    }
    if (curr == nullptr) return false;

    if (isLeft) {
      if (curr->left != nullptr) return false;
      if (value >= curr->data) return false;
      if (hasLo && value < lo) return false;
      curr->left = new Node(value);
    } else {
      if (curr->right != nullptr) return false;
      if (value < curr->data) return false;
      if (hasHi && value >= hi) return false;
      curr->right = new Node(value);
    }
    return true;
  }

public:
  BinarySearchTree() { root = nullptr; }
  ~BinarySearchTree() { destroy(root); }

  BinarySearchTree(const BinarySearchTree &) = delete;
  BinarySearchTree &operator=(const BinarySearchTree &) = delete;

  void insert(int value) { insert(root, value); }
  bool insertLeft(int parentValue, int value) {
    return insertChild(parentValue, value, true);
  }
  bool insertRight(int parentValue, int value) {
    return insertChild(parentValue, value, false);
  }

  void preorder() { preorder(root); cout << endl; }
  void inorder() { inorder(root); cout << endl; }
  void postorder() { postorder(root); cout << endl; }
  bool search(int value) { return search(root, value); }

  bool findMin(int &result) {
    if (root == nullptr) return false;
    Node *curr = root;
    while (curr->left != nullptr) curr = curr->left;
    result = curr->data;
    return true;
  }

  bool findMax(int &result) {
    if (root == nullptr) return false;
    Node *curr = root;
    while (curr->right != nullptr) curr = curr->right;
    result = curr->data;
    return true;
  }
};

int main() {
  BinarySearchTree tree;

  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);

  cout << "Preorder:  "; tree.preorder();
  cout << "Inorder:   "; tree.inorder();
  cout << "Postorder: "; tree.postorder();

  cout << "Search 40: " << (tree.search(40) ? "found" : "not found") << endl;
  cout << "Search 99: " << (tree.search(99) ? "found" : "not found") << endl;

  int value;
  if (tree.findMin(value)) cout << "Min: " << value << endl;
  if (tree.findMax(value)) cout << "Max: " << value << endl;

  cout << "insertLeft(20, 10):  " << (tree.insertLeft(20, 10) ? "ok" : "rejected") << endl;
  cout << "insertRight(70, 80): " << (tree.insertRight(70, 80) ? "ok" : "rejected") << endl;
  cout << "insertLeft(70, 60):  " << (tree.insertLeft(70, 60) ? "ok" : "rejected") << endl;
  cout << "insertRight(40, 35): " << (tree.insertRight(40, 35) ? "ok" : "rejected") << endl;
  cout << "insertLeft(30, 5):   " << (tree.insertLeft(30, 5) ? "ok" : "rejected") << endl;

  cout << "Inorder:   "; tree.inorder();

  return 0;
}