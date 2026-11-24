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
    cout << root->key << ":" << root->size << " ";
    preOrder(root->left);
    preOrder(root->right);
  }













  unsigned long long orders(Node *root) {
    if (root == nullptr) {
      return 1;
    }

    int L = 0;
    int R = 0;

    if (root->left != nullptr) {
      L = root->left->size;
    }

    if (root->right != nullptr) {
      R = root->right->size;
    }

    unsigned long long O = factorial(L + R) / (factorial(L) * factorial(R));

    O = O * orders(root->left) * orders(root->right);

    return O;
  }

  long long factorial(int n) {
    if (n == 0 || n == 1)
      return 1;

    return n * factorial(n - 1);
  }














  void search(int key) {
    Node *curr = root;
    cout << "SEARCH " << key << ": ";
    while (curr != nullptr) {
      cout << curr->key << " ";

      if (curr->key == key) {
        cout << "FOUND" << endl;
        return;
      } else if (key < curr->key) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }

    cout << "NOT FOUND" << endl;
  }











  void updateSize(Node *root) {
    if (root == nullptr)
      return;

    root->size = 1;

    if (root->left != nullptr)
      root->size += root->left->size;

    if (root->right != nullptr)
      root->size += root->right->size;
  }













  int findMinDelete(Node *&root) {
    if (root->left == nullptr) {
      int k = root->key;
      Node *temp = root;
      root = root->right;
      delete temp;
      return k;
    }

    int k = findMinDelete(root->left);
    updateSize(root);
    return k;
  }










  int findMaxDelete(Node *&root) {
    if (root->right == nullptr) {
      int k = root->key;
      Node *temp = root;
      root = root->left;
      delete temp;
      return k;
    }

    int k = findMaxDelete(root->right);
    updateSize(root);
    return k;
  }

  void deleteKey(int key, bool useSuccessor) {
    cout << "TEST0 DELETE " << key << " ";
    deleteNode(root, key, useSuccessor);
  }













  void deleteNode(Node *&root, int key, bool useSuccessor) {

    if (root == nullptr) {
      cout << "NOT FOUND" << endl;
      return;
    }

    if (key < root->key) {
      deleteNode(root->left, key, useSuccessor);
    } else if (key > root->key) {
      deleteNode(root->right, key, useSuccessor);
    } else {

      if (root->left == nullptr && root->right == nullptr) {

        cout << "CASE 1" << endl;

        delete root;
        root = nullptr;
        return;
      }

      else if (root->left == nullptr || root->right == nullptr) {

        cout << "CASE 2" << endl;

        Node *temp = root;

        if (root->left != nullptr)
          root = root->left;
        else
          root = root->right;

        delete temp;
      }

      else {

        cout << "CASE 3 ";

        int replacement;

        if (useSuccessor) {
          replacement = findMinDelete(root->right);
        } else {
          replacement = findMaxDelete(root->left);
        }

        cout << "REPLACEMENT " << replacement << endl;

        root->key = replacement;
      }
    }

    updateSize(root);
  }









  int select(int i, Node *root) {

    if (root == nullptr) {
      return -1;
    }

    int leftSize = 0;

    if (root->left != nullptr) {
      leftSize = root->left->size;
    }

    if (i == leftSize + 1) {
      return root->key;
    } else if (i <= leftSize) {
      return select(i, root->left);
    } else {
      return select(i - leftSize - 1, root->right);
    }
  }











  void select(int i) {

    int result = select(i, root);

    cout << "SELECT " << i << ": ";

    if (result == -1) {
      cout << "NOT FOUND" << endl;
    } else {
      cout << result << endl;
    }
  }











  int rank(int x, Node *root) {

    if (root == nullptr) {
      return 0;
    }

    if (x <= root->key) {
      return rank(x, root->left);
    } else {
      int leftSize = 0;

      if (root->left != nullptr) {
        leftSize = root->left->size;
      }

      return leftSize + 1 + rank(x, root->right);
    }
  }












  void rank(int x) {

    int result = rank(x, root);

    cout << "RANK " << x << ": " << result << endl;
  }

















  bool checkBST(Node *root, int min, int max) {

    if (root == nullptr) {
      return true;
    }

    if (root->key <= min || root->key >= max) {
      return false;
    }

    int correctSize = 1;

    if (root->left != nullptr) {
      correctSize += root->left->size;
    }

    if (root->right != nullptr) {
      correctSize += root->right->size;
    }

    if (root->size != correctSize) {
      return false;
    }

    return checkBST(root->left, min, root->key) &&
           checkBST(root->right, root->key, max);
  }










  void isBST() {

    bool result = checkBST(root, -1000000, 1000000);

    if (result) {
      cout << "ISBST: YES" << endl;
    } else {
      cout << "ISBST: NO" << endl;
    }
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

  cout << "TEST0 PREORDER: ";
  tree.preOrder(tree.root);
  cout << "\nTEST0 ORDERS: " << tree.orders(tree.root) << endl;

  cout << "TEST0 DELETE 4 CASE 1" << endl;
  tree.deleteKey(4, true);
  cout << "TEST0 PREORDER: ";
  tree.preOrder(tree.root);
  cout << endl;

  cout << "TEST0 DELETE 5 CASE 2" << endl;
  tree.deleteKey(5, true);
  cout << "TEST0 PREORDER: ";
  tree.preOrder(tree.root);
  cout << endl;

  cout << "TEST0 DELETE 10 CASE 3 REPLACED BY 11" << endl;
  tree.deleteKey(10, true);
  cout << "TEST0 PREORDER: ";
  tree.preOrder(tree.root);
  cout << endl;
  cout << "PREORDER: ";
  tree.preOrder(tree.root);
  cout << "\nORDERS: " << tree.orders(tree.root) << endl;
  tree.isBST();

  tree.search(99);
  tree.select(10);
  tree.rank(50);

  return 0;
}
