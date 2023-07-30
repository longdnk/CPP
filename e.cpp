#include "bits/stdc++.h"

using namespace std;
struct Node {
    int value;
    Node *left;
    Node *right;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->left = p->right = nullptr;
    return p;
}

void insertNode(Node *&root, int k) {
    if (root == nullptr) {
        root = createNode(k);
    }
    else if (root->value > k) {
        insertNode(root->left, k);
    }
    else {
        insertNode(root->right, k);
    }
}

Node *findNode(Node *root, int k) {
    if (root == nullptr || root->value == k) {
        return root;
    }
    else if (root->value > k) {
        return findNode(root->left, k);
    }
    else {
        return findNode(root->right, k);
    }
}

Node *findValue(Node *root, int k) {
    Node *p = root;
    while (p != nullptr && p->value != k) {
        if (p->value > k) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    return p;
}

Node *findMaxBelow(Node *root, int k) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->value > k) {
        return findMaxBelow(root->left, k);
    }
    Node *tmp = findMaxBelow(root->right, k);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->value < k) {
        return root;
    }
    return findMaxBelow(root->left, k);
}

Node *findMinAbove(Node *root, int k) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->value < k) {
        return findMinAbove(root->right, k);
    }
    Node *tmp = findMinAbove(root->left, k);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->value > k) {
        return root;
    }
    return findMinAbove(root->right, k);
}

Node *findMaxEvenX(Node *root, int x) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->value > x) {
        return findMaxEvenX(root->left, x);
    }
    Node *tmp = findMaxEvenX(root->right, x);
    if (tmp != nullptr) {
        return tmp;
    }
    if (root->value <= x && root->value % 2 == 0) {
        return root;
    }
    return findMaxEvenX(root->left, x);
}

bool validBST(Node *root, int left, int right) {
    if (root == nullptr) {
        return true;
    }
    if (root->value > left && root->value < right) {
        return validBST(root->left, left, root->value) && validBST(root->right, root->value, right);
    }
    return false;
}

bool checkBST(Node *root) {
    return validBST(root, 1 << 31, ~(1 << 31));
}

bool isSubTree(Node *root, int keyRoot, int keyLeft, int keyRight) {
    if (root == nullptr) {
        return false;
    }
    if (root->left != nullptr && root->right != nullptr && root->value == keyRoot &&
        root->left->value == keyLeft && root->right->value == keyRight) {
        return true;
    }
    return isSubTree(root->left, keyRoot, keyLeft, keyRight) || isSubTree(root->right, keyRoot, keyLeft, keyRight);
}

bool checkSubTree(Node *root, Node *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
        return true;
    }
    if (root == nullptr || subRoot == nullptr) {
        return false;
    }
    if (root->value != subRoot->value) {
        return false;
    }
    return checkSubTree(root->left, subRoot->left) && checkSubTree(root->right, subRoot->right);
}

bool IsSubTree(Node *root, Node *subRoot) {
    if (checkSubTree(root, subRoot)) {
        return true;
    }
    if (root == nullptr) {
        return false;
    }
    return IsSubTree(root->left, subRoot) || IsSubTree(root->right, subRoot);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << LONG_MIN << '\n';
}