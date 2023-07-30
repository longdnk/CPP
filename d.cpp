#include "bits/stdc++.h"

using namespace std;
struct Node {
    int value;
    Node *next;
};

bool isEmpty(Node *head) {
    return head == nullptr;
}

void sortList(Node *&head) {
    if (!isEmpty(head)) {
        Node *currentNode = head;
        Node *nextNode;
        while (currentNode != nullptr) {
            nextNode = currentNode->next;
            while (nextNode != nullptr) {
                if (currentNode->value > nextNode->value) {
                    int tmp = currentNode->value;
                    currentNode->value = nextNode->value;
                    nextNode->value = tmp;
                }
                nextNode = nextNode->next;
            }
            currentNode = currentNode->next;
        }
    }
}

Node *split(Node *head) {
    Node *first = head;
    Node *second = head;
    while (first->next != nullptr && first->next->next != nullptr) {
        first = first->next->next;
        second = second->next;
    }
    Node *tmp = second->next;
    second->next = nullptr;
    return tmp;
}

Node *mergeList(Node *first, Node *second) {
    if (!first) {
        return second;
    }
    if (!second) {
        return first;
    }
    if (first->value < second->value) {
        first->next = mergeList(first->next, second);
        return first;
    }
    else {
        second->next = mergeList(first, second->next);
        return second;
    }
}

Node *mergeSort(Node *&head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return mergeList(head, second);
}

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = nullptr;
    return p;
}

void addLast(Node *&head, int k) {
    Node *p = createNode(k);
    if (isEmpty(head)) {
        head = p;
    }
    else {
        Node *last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = p;
    }
}

void output(Node *head) {
    while (!isEmpty(head)) {
        cout << head->value << ' ';
        head = head->next;
    }
    cout << '\n';
}

int getMax(int a, int b) {
    return a > b ? a : b;
}

int findMaxBelow(Node *head, int x) {
    int res = -1e9;
    while (!isEmpty(head)) {
        if (head->value < x) {
            res = getMax(res, head->value);
        }
        head = head->next;
    }
    return res;
}

int getMin(int a, int b) {
    return a < b ? a : b;
}

int findMinAbove(Node *head, int x) {
    int res = 1e9;
    while (!isEmpty(head)) {
        if (head->value > x) {
            res = min(res, head->value);
        }
        head = head->next;
    }
    return res;
}

bool deleteNode(Node *head, int x) {
    if (!isEmpty(head)) {
        Node *p = head;
        Node *prev = nullptr;
        while (p != nullptr && p->value != x) {
            prev = p;
            p = p->next;
        }
        if (p != nullptr) {
            if (prev == nullptr) {
                Node *tmp = head;
                head = tmp->next;
                tmp->next = nullptr;
                delete tmp;
            }
            else {
                prev->next = p->next;
                p->next = nullptr;
                delete p;
            }
        }
        return true;
    }
    return false;
}

bool isExist(Node *head, int value) {
    while (!isEmpty(head)) {
        if (head->value == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void removeNodeHaveK(Node *&head, int k) {
    while (isExist(head, k)) {
        deleteNode(head, k);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *head = nullptr;
    addLast(head, 50);
    addLast(head, 10);
    addLast(head, 20);
    addLast(head, 40);
    addLast(head, 30);
    addLast(head, 11);
    mergeSort(head);
    output(head);
    // cout << findMaxBelow(head, 11) << '\n';
    // cout << findMinAbove(head, 11) << '\n';
}