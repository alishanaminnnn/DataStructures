#include <iostream>
using namespace std;

// Roll 25P-0048. R is the last four digits, so R = 48 (even: inorder successor).
// D1, D2 and D3 are taken from the Part A drawing, one deletion after the other:
// D1 = largest leaf, D2 = smallest key with one child, D3 = smallest key with two children.

class node {
public:
    int key;
    int size;
    node *left;
    node *right;

    node(int value) {
        key = value;
        size = 1;
        left = nullptr;
        right = nullptr;
    }
};

class bin_search_tree {
public:
    node *root;

    bin_search_tree() {
        root = nullptr;
    }

    // Returns false when the key is already in the tree. Sizes stay unchanged then.
    bool b_search_tree(node *&current, int key) {
        if (current == nullptr) {
            current = new node(key);
            return true;
        }

        if (key == current->key) {
            return false;
        }

        bool inserted;
        if (key < current->key) {
            inserted = b_search_tree(current->left, key);
        } else {
            inserted = b_search_tree(current->right, key);
        }

        if (inserted) {
            fixSize(current);
        }
        return inserted;
    }

    void in_order(node *current) {
        if (current == nullptr) {
            return;
        }
        in_order(current->left);
        cout << current->key << " ";
        in_order(current->right);
    }

    void pre_order(node *current) {
        if (current == nullptr) {
            return;
        }
        cout << current->key << ":" << current->size << " ";
        pre_order(current->left);
        pre_order(current->right);
    }

    // Iterative. Prints every key on the path, then FOUND or NOT FOUND.
    void search(int key) {
        node *current = root;
        bool found = false;

        while (current != nullptr) {
            cout << current->key << " ";
            if (key == current->key) {
                found = true;
                break;
            }
            if (key < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (found) {
            cout << "FOUND";
        } else {
            cout << "NOT FOUND";
        }
    }

    // whichCase is 1, 2 or 3. replacement is set only for case 3.
    // The node that is freed in case 3 is the successor or predecessor, not the
    // node whose key we overwrite. That node stays, and its size drops because
    // the removed node was inside its subtree.
    int deleteKey(int key, bool useSuccessor, int &replacement) {
        int whichCase = 0;
        replacement = 0;
        root = removeNode(root, key, useSuccessor, whichCase, replacement);
        return whichCase;
    }

    // One path from the root. leftSize + 1 is this node's place in sorted order.
    int select(int i) {
        node *current = root;

        while (current != nullptr) {
            int leftSize = subtreeSize(current->left);
            if (i == leftSize + 1) {
                return current->key;
            }
            if (i <= leftSize) {
                current = current->left;
            } else {
                i = i - leftSize - 1;
                current = current->right;
            }
        }
        return -1;
    }

    // One path. Counts keys strictly smaller than x, even if x is missing.
    int rank(int x) {
        node *current = root;
        int smaller = 0;

        while (current != nullptr) {
            if (x <= current->key) {
                current = current->left;
            } else {
                smaller = smaller + subtreeSize(current->left) + 1;
                current = current->right;
            }
        }
        return smaller;
    }

    // Keys k with lo <= k <= hi. rank(hi + 1) is how many keys are <= hi.
    int countRange(int lo, int hi) {
        return rank(hi + 1) - rank(lo);
    }

    // Root is fixed first. The other keys are shuffled between the two subtrees.
    unsigned long long orders(node *current) {
        if (current == nullptr) {
            return 1;
        }

        int leftSize = subtreeSize(current->left);
        int rightSize = subtreeSize(current->right);
        unsigned long long ways = nChooseK(leftSize + rightSize, leftSize);
        return ways * orders(current->left) * orders(current->right);
    }

    // Real BST rule: whole left subtree smaller, whole right subtree larger.
    // Also every stored size must be 1 + left size + right size.
    bool isBST() {
        return checkBST(root, false, 0, false, 0);
    }

    // Swap every pair of keys, test only the slide's child rule, then swap back.
    void badSwaps(int &count, int &firstA, int &firstB) {
        node *nodes[32];
        int n = 0;
        collect(root, nodes, n);
        sortByKey(nodes, n);

        count = 0;
        firstA = 0;
        firstB = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = nodes[i]->key;
                int b = nodes[j]->key;
                nodes[i]->key = b;
                nodes[j]->key = a;

                if (slideRule(root)) {
                    count++;
                    if (count == 1) {
                        firstA = a;
                        firstB = b;
                    }
                }

                nodes[i]->key = a;
                nodes[j]->key = b;
            }
        }
    }

    // Full walk, not BST search. After a bad swap the tree is not a BST,
    // so the second swap still has to find the two keys.
    void swapKeys(int a, int b) {
        node *nodeA = findKey(root, a);
        node *nodeB = findKey(root, b);
        int temp = nodeA->key;
        nodeA->key = nodeB->key;
        nodeB->key = temp;
    }

private:
    int subtreeSize(node *current) {
        if (current == nullptr) {
            return 0;
        }
        return current->size;
    }

    void fixSize(node *current) {
        current->size = 1 + subtreeSize(current->left) + subtreeSize(current->right);
    }

    node *removeNode(node *current, int key, bool useSuccessor, int &whichCase, int &replacement) {
        if (current == nullptr) {
            return nullptr;
        }

        if (key < current->key) {
            current->left = removeNode(current->left, key, useSuccessor, whichCase, replacement);
            fixSize(current);
            return current;
        }
        if (key > current->key) {
            current->right = removeNode(current->right, key, useSuccessor, whichCase, replacement);
            fixSize(current);
            return current;
        }

        if (current->left == nullptr && current->right == nullptr) {
            whichCase = 1;
            delete current;
            return nullptr;
        }

        if (current->left == nullptr || current->right == nullptr) {
            whichCase = 2;
            node *child = current->left;
            if (child == nullptr) {
                child = current->right;
            }
            delete current;
            return child;
        }

        whichCase = 3;
        int ignoredCase = 0;
        int ignoredReplacement = 0;

        if (useSuccessor) {
            node *successor = current->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            replacement = successor->key;
            current->key = replacement;
            current->right = removeNode(current->right, replacement, useSuccessor, ignoredCase, ignoredReplacement);
        } else {
            node *predecessor = current->left;
            while (predecessor->right != nullptr) {
                predecessor = predecessor->right;
            }
            replacement = predecessor->key;
            current->key = replacement;
            current->left = removeNode(current->left, replacement, useSuccessor, ignoredCase, ignoredReplacement);
        }

        fixSize(current);
        return current;
    }

    bool checkBST(node *current, bool hasLow, int low, bool hasHigh, int high) {
        if (current == nullptr) {
            return true;
        }
        if (hasLow && current->key <= low) {
            return false;
        }
        if (hasHigh && current->key >= high) {
            return false;
        }
        if (current->size != 1 + subtreeSize(current->left) + subtreeSize(current->right)) {
            return false;
        }
        return checkBST(current->left, hasLow, low, true, current->key) &&
               checkBST(current->right, true, current->key, hasHigh, high);
    }

    bool slideRule(node *current) {
        if (current == nullptr) {
            return true;
        }
        if (current->left != nullptr && current->key <= current->left->key) {
            return false;
        }
        if (current->right != nullptr && current->key >= current->right->key) {
            return false;
        }
        return slideRule(current->left) && slideRule(current->right);
    }

    void collect(node *current, node *arr[], int &n) {
        if (current == nullptr) {
            return;
        }
        collect(current->left, arr, n);
        arr[n] = current;
        n++;
        collect(current->right, arr, n);
    }

    void sortByKey(node *arr[], int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (arr[j]->key > arr[j + 1]->key) {
                    node *temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    node *findKey(node *current, int key) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->key == key) {
            return current;
        }
        node *leftHit = findKey(current->left, key);
        if (leftHit != nullptr) {
            return leftHit;
        }
        return findKey(current->right, key);
    }

    unsigned long long nChooseK(int n, int k) {
        if (k > n - k) {
            k = n - k;
        }
        unsigned long long result = 1;
        for (int i = 1; i <= k; i++) {
            result = result * (unsigned long long)(n - k + i) / (unsigned long long)i;
        }
        return result;
    }
};

void generateKeys(int R, int keys[], int n) {
    int s = R + 1;
    int count = 0;
    while (count < n) {
        s = (s * 7) % 10007;
        int k = 10 + s % 90;
        bool used = false;
        for (int j = 0; j < count; j++) {
            if (keys[j] == k) {
                used = true;
            }
        }
        if (!used) {
            keys[count++] = k;
        }
    }
}

void printPreorder(const char *label, bin_search_tree &tree) {
    cout << label;
    tree.pre_order(tree.root);
    cout << endl;
}

void printDelete(const char *prefix, int key, int whichCase, int replacement) {
    cout << prefix << "DELETE " << key << " CASE " << whichCase;
    if (whichCase == 3) {
        cout << " REPLACED BY " << replacement;
    }
    cout << endl;
}

void printYesNo(bool yes) {
    if (yes) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    bin_search_tree test;
    int testKeys[16] = {7, 6, 10, 1, 8, 15, 5, 9, 13, 16, 3, 11, 14, 2, 4, 12};
    for (int i = 0; i < 16; i++) {
        test.b_search_tree(test.root, testKeys[i]);
    }

    printPreorder("TEST0 PREORDER: ", test);
    cout << "TEST0 ORDERS: " << test.orders(test.root) << endl;

    int replacement = 0;
    int whichCase = test.deleteKey(4, true, replacement);
    printDelete("TEST0 ", 4, whichCase, replacement);
    printPreorder("TEST0 PREORDER: ", test);

    whichCase = test.deleteKey(5, true, replacement);
    printDelete("TEST0 ", 5, whichCase, replacement);
    printPreorder("TEST0 PREORDER: ", test);

    whichCase = test.deleteKey(10, true, replacement);
    printDelete("TEST0 ", 10, whichCase, replacement);
    printPreorder("TEST0 PREORDER: ", test);

    int R = 48;
    bool useSuccessor = (R % 2 == 0);
    int keys[13];
    generateKeys(R, keys, 13);

    bin_search_tree tree;
    for (int i = 0; i < 13; i++) {
        tree.b_search_tree(tree.root, keys[i]);
    }

    cout << "ROLL " << (R / 1000) % 10 << (R / 100) % 10 << (R / 10) % 10 << R % 10;
    cout << " RULE ";
    if (useSuccessor) {
        cout << "successor" << endl;
    } else {
        cout << "predecessor" << endl;
    }

    cout << "KEYS:";
    for (int i = 0; i < 13; i++) {
        cout << " " << keys[i];
    }
    cout << endl;

    printPreorder("PREORDER: ", tree);
    cout << "ORDERS: " << tree.orders(tree.root) << endl;
    cout << "ISBST: ";
    printYesNo(tree.isBST());

    bool inserted = tree.b_search_tree(tree.root, keys[0]);
    cout << "INSERT " << keys[0] << ": ";
    if (inserted) {
        cout << "OK" << endl;
    } else {
        cout << "DUPLICATE" << endl;
    }
    printPreorder("PREORDER: ", tree);

    int swapCount = 0;
    int firstA = 0;
    int firstB = 0;
    tree.badSwaps(swapCount, firstA, firstB);
    cout << "BAD SWAPS: " << swapCount << " FIRST " << firstA << " " << firstB << endl;

    cout << "SWAP " << firstA << " " << firstB << endl;
    tree.swapKeys(firstA, firstB);
    cout << "ISBST: ";
    printYesNo(tree.isBST());

    cout << "SEARCH " << firstA << ": ";
    tree.search(firstA);
    cout << endl;
    cout << "SEARCH " << firstB << ": ";
    tree.search(firstB);
    cout << endl;

    cout << "SWAP " << firstA << " " << firstB << endl;
    tree.swapKeys(firstA, firstB);
    cout << "ISBST: ";
    printYesNo(tree.isBST());

    int selectIndex = (R % 13) + 1;
    cout << "SELECT " << selectIndex << ": " << tree.select(selectIndex) << endl;

    int S2 = keys[2] + 1;
    bool s2Used = true;
    while (s2Used) {
        s2Used = false;
        for (int i = 0; i < 13; i++) {
            if (keys[i] == S2) {
                s2Used = true;
            }
        }
        if (s2Used) {
            S2++;
        }
    }
    cout << "RANK " << S2 << ": " << tree.rank(S2) << endl;

    int lo = keys[1];
    int hi = keys[4];
    if (lo > hi) {
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    cout << "RANGE " << lo << " " << hi << ": " << tree.countRange(lo, hi) << endl;

    int D1 = 85;
    int D2 = 59;
    int D3 = 22;

    whichCase = tree.deleteKey(D1, useSuccessor, replacement);
    printDelete("", D1, whichCase, replacement);
    printPreorder("PREORDER: ", tree);

    whichCase = tree.deleteKey(D2, useSuccessor, replacement);
    printDelete("", D2, whichCase, replacement);
    printPreorder("PREORDER: ", tree);

    whichCase = tree.deleteKey(D3, useSuccessor, replacement);
    printDelete("", D3, whichCase, replacement);
    printPreorder("PREORDER: ", tree);

    cout << "ORDERS: " << tree.orders(tree.root) << endl;

    int selectJ = (R % 10) + 1;
    cout << "SELECT " << selectJ << ": " << tree.select(selectJ) << endl;
    cout << "RANK " << D1 << ": " << tree.rank(D1) << endl;
    cout << "ISBST: ";
    printYesNo(tree.isBST());

    return 0;
}
