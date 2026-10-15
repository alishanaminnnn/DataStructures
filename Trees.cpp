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

  // Root, Left, Right
  void preorder(Node *curr) {
    if (curr == nullptr) return;
    cout << curr->data << " ";
    preorder(curr->left);
    preorder(curr->right);
  }

  // Left, Root, Right
  void inorder(Node *curr) {
    if (curr == nullptr) return;
    inorder(curr->left);
    cout << curr->data << " ";
    inorder(curr->right);
  }

  // Left, Right, Root
  void postorder(Node *curr) {
    if (curr == nullptr) return;
    postorder(curr->left);
    postorder(curr->right);
    cout << curr->data << " ";
  }

  void destroy(Node *curr) {
    if (curr == nullptr) return;
    destroy(curr->left);
    destroy(curr->right);
    delete curr;
  }

public:
  BinarySearchTree() { root = nullptr; }
  ~BinarySearchTree() { destroy(root); }

  BinarySearchTree(const BinarySearchTree &) = delete;
  BinarySearchTree &operator=(const BinarySearchTree &) = delete;

  void insert(int value) { insert(root, value); }
  void preorder() { preorder(root); cout << endl; }
  void inorder() { inorder(root); cout << endl; }
  void postorder() { postorder(root); cout << endl; }
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

  return 0;
}