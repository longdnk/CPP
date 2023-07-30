#include "bits/stdc++.h"

using namespace std;
template <class T>
struct Node {
    int key;
    Node *pLeft;
    Node *pRight;
    Node *pParent;
};

Node<class T> *createNode(int x) {
    Node<T> *p = new Node<T>;
    p->key = x;
    p->pLeft = p->pRight = p->pParent = nullptr;
    return p;
}

void insert(Node<T> *&root, int value, Node<T> *parent) {
    Node<T> *p = createNode(value);
    if (root == nullptr) {
        p->pParent = parent;
        root = p;
    }
    else if (root->key > value) {
        insert(root->pLeft, value, root);
    }
    else {
        insert(root->pRight, value, root);
    }
}

void insertNode(Node<T> *&root, int k) {
    insert(root, k, nullptr);
}

Node<T> *convertArrayToTree(int a[], int n) {
    Node<T> *tmp = nullptr;
    for (int i = 0; i < n; ++i) {
        insertNode(tmp, a[i]);
    }
    return tmp;
}

Node<T> *searchTree(Node<T> *root, int k) {
    if (root == nullptr || root->key == k) {
        return root;
    }
    else if (root->key > k) {
        return searchTree(root->pLeft, k);
    }
    else {
        return searchTree(root->pRight, k);
    }
}

Node<T> *searchValue(Node<T> *root, int k) {
    Node<T> *p = root;
    while (p != nullptr && p->key != k) {
        if (p->key > k) {
            p = p->pLeft;
        }
        else {
            p = p->pRight;
        }
    }
    return p;
}

void deleteNode(Node<T> *&root, int x) {
    Node<T> *p = root;
    Node<T> *parent = nullptr;
    while (p != nullptr && p->key != x) {
        parent = p;
        if (p->key > x) {
            p = p->pLeft;
        }
        else {
            p = p->pRight;
        }
    }
    if (p != nullptr) {
        if (p->pLeft != nullptr && p->pRight != nullptr) {
            parent = p;
            Node<T> *t = p->pRight;
            while (t->pLeft != nullptr) {
                parent = t;
                t = t->pLeft;
            }
            p->key = t->key;
            p = t;
        }
        Node<T> *r;
        if (p->pLeft == nullptr) {
            r = p->pRight;
        }
        else {
            r = p->pLeft;
        }
        if (parent == nullptr) {
            root = r;
        }
        else {
            if (parent->key > p->key) {
                parent->pLeft = r;
            }
            else {
                parent->pRight = r;
            }
        }
        delete p;
    }
}

int removeNode(Node<T> *&root, int k) {
    if (searchTree(root, k) != nullptr) {
        deleteNode(root, k);
        return 1;
    }
    return 0;
}

void output(Node<T> *root) {
    if (root == nullptr) {
        return;
    }
    output(root->pLeft);
    output(root->pRight);
    cout << root->key << ' ';
}

void printLeaves(Node<T> *root) {
    if (root == nullptr) {
        return;
    }
    printLeaves(root->pRight);
    printLeaves(root->pLeft);
    if (root->pLeft == nullptr && root->pRight == nullptr) {
        cout << root->key << ' ';
    }
}

Node<T> *findMaxBelow(Node<T> *root, int k) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->key > k) {
        return findMaxBelow(root->pLeft, k);
    }
    Node<T> *tmp = findMaxBelow(root->pRight, k);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->key < k) {
        return root;
    }
    return findMaxBelow(root->pLeft, k);
}

Node<T> *findMaxEvenX(Node<T> *root, int x) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->key > x) {
        return findMaxEvenX(root->pLeft, x);
    }
    Node<T> *tmp = findMaxEvenX(root->pRight, x);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->key < x && root->key % 2 == 0) {
        return root;
    }
    return findMaxEvenX(root->pLeft, x);
}

Node<T> *findMinEvenX(Node<T> *root, int x) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->key < x) {
        return findMinEvenX(root->pRight, x);
    }
    Node<T> *tmp = findMinEvenX(root->pLeft, x);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->key > x && root->key % 2 == 0) {
        return root;
    }
    return findMinEvenX(root->pRight, x);
}

bool isSubTree(Node<T> *root, int keyRoot, int keyLeft, int keyRight) {
    if (root == nullptr) {
        return false;
    }
    if (root->pLeft != nullptr && root->pRight != nullptr && root->key == keyRoot
        && root->pLeft->key == keyLeft && root->pRight->key == keyRight) {
        return true;
    }
    return isSubTree(root->pLeft, keyRoot, keyLeft, keyRight) || isSubTree(root->pRight, keyRoot, keyLeft, keyRight);
}

bool checkSubTree(Node<T> *root, Node<T> *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
        return true;
    }
    if (root == nullptr || subRoot == nullptr) {
        return false;
    }
    if (root->key != subRoot->key) {
        return false;
    }
    return checkSubTree(root->pLeft, subRoot->pLeft) && checkSubTree(root->pRight, subRoot->pRight);
}

bool IsSubTree(Node<T> *root, Node<T> *subRoot) {
    if (checkSubTree(root, subRoot)) {
        return true;
    }
    if (root == nullptr) {
        return false;
    }
    return IsSubTree(root->pLeft, subRoot) || IsSubTree(root->pRight, subRoot);
}

Node<T> *completeSubTree(Node<T> *subRoot, int keyRoot, int keyLeft, int keyRight) {
    insertNode(subRoot, keyRoot);
    insertNode(subRoot, keyLeft);
    insertNode(subRoot, keyRight);
    return subRoot;
}

bool checkSub(Node<T> *root, Node<T> *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
        return true;
    }
    if (root == nullptr || subRoot == nullptr) {
        return false;
    }
    if (root->key != subRoot->key) {
        return false;
    }
    return checkSub(root->pLeft, subRoot->pLeft) && checkSub(root->pRight, subRoot->pRight);
}

bool isValid(Node<T> *root, Node<T> *subRoot) {
    if (checkSub(root, subRoot)) {
        return true;
    }
    if (root == nullptr) {
        return false;
    }
    return isValid(root->pLeft, subRoot) || isValid(root->pRight, subRoot);
}

bool isSub(Node<T> *root, int keyRoot, int keyLeft, int keyRight) {
    Node<T> *subRoot = nullptr;
    subRoot = completeSubTree(subRoot, keyRoot, keyLeft, keyRight);
    return isValid(root, subRoot);
}

bool validBST(Node<T> *root, int left, int right) {
    if (root == nullptr) {
        return true;
    }
    if (root->key <= left || root->key >= right) {
        return false;
    }
    return validBST(root->pLeft, left, root->key) && validBST(root->pRight, root->key, right);
}

bool checkBST(Node<T> *root) {
    const int INF = 1e6;
    return validBST(root, -INF, INF);
}

Node<T> *findNumber(Node<T> *root, int m) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->key > m) {
        return findNumber(root->pLeft, m);
    }
    Node<T> *tmp = findNumber(root->pRight, m);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->key <= m) {
        return root;
    }
    return findNumber(root->pLeft, m);
}

Node<T> *findingNumber(Node<T> *root, int m) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->key < m) {
        return findingNumber(root->pRight, m);
    }
    Node<T> *tmp = findingNumber(root->pLeft, m);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->key >= m) {
        return root;
    }
    return findingNumber(root->pRight, m);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node<T> *root = nullptr;
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);
}