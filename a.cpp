//
// Created by longdnk on 12/20/2022.
//
#include <bits/stdc++.h>

using namespace std;
#define null NULL

struct Node {
    int value;
    Node *next;
};

void init(Node *&head) {
    head = null;
}

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = null;
    return p;
}

bool checkEmpty(Node *head) {
    return head != null;
}

void addFirst(Node *&head, int x) {
    Node *p = createNode(x);
    p->next = head;
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = createNode(x);
    if (!checkEmpty(head)) {
        head = p;
    } else {
        Node *last = head;
        while (last->next != null) {
            last = last->next;
        }
        last->next = p;
    }
}

void addAfter(Node *head, int v, int x) {
    Node *p = createNode(x);
    Node *q = head;
    while (q != null && q->value != v) {
        q = q->next;
    }
    if (q != null) {
        p->next = q->next;
        q->next = p;
    }
}

void addBefore(Node *&head, int v, int x) {
    Node *p = createNode(x);
    Node *q = head;
    Node *tmp = head;
    while (q != null && q->value != v) {
        tmp = q;
        q = q->next;
    }
    if (head->value == tmp->value) {
        addFirst(head, x);
    } else {
        tmp->next = p;
        p->next = q;
    }
}

void deleteFirst(Node *&head) {
    if (checkEmpty(head)) {
        Node *p = head;
        head = p->next;
        p->next = null;
        delete (p);
    }
}

void deleteLast(Node *&head) {
    if (checkEmpty(head)) {
        Node *last = head;
        Node *q = head;
        while (last->next != null) {
            q = last;
            last = last->next;
        }
        q->next = null;
        last->next = null;
        delete (last);
    }
}

void deleteNode(Node *&head, int v) {
    if (checkEmpty(head)) {
        Node *p = head;
        Node *prev = null;
        while (p != null && p->value != v) {
            prev = p;
            p = p->next;
        }
        if (p != null) {
            if (prev == null) {
                Node *tmp = head;
                head = tmp->next;
                tmp->next = null;
                delete (tmp);
            } else {
                prev->next = p->next;
                p->next = null;
                delete (p);
            }
        }
    }
}

void deleteBefore(Node *&head, int v) {
    if (checkEmpty(head)) {
        Node *q = head;
        Node *p = null;
        while (q != null && q->value != v) {
            p = q;
            q = q->next;
        }
        deleteNode(head, p->value);
    }
}

void deleteAfter(Node *&head, int v) {
    if (checkEmpty(head)) {
        Node *q = head;
        Node *p = head;
        while (q != null && q->value != v) {
            q = q->next;
            p = q->next->next;
        }
        deleteNode(head, p->value);
    }
}

void output(Node *head) {
    while (head != null) {
        cout << head->value << ' ';
        head = head->next;
    }
}

int calcSum(Node *head) {
    int sum = 0;
    while (head != null) {
        sum += head->value;
        head = head->next;
    }
    return sum;
}

int countList(Node *head) {
    int cnt = 0;
    while (head != null) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

int countEven(Node *head) {
    int cnt = 0;
    while (checkEmpty(head)) {
        cnt += !(head->value & 1);
        head = head->next;
    }
    return cnt;
}

void outputLarger(Node *head) {
    while (checkEmpty(head)) {
        if (head->value > 0) {
            cout << head->value << ' ';
        }
        head = head->next;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *head;
    init(head);
    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);
    addLast(head, 10);
    addLast(head, 20);
    addLast(head, 30);
    addAfter(head, 30, 50);
    addBefore(head, 10, 100);
//    cout << calcSum(head) << '\n';
    deleteFirst(head);
    deleteLast(head);
    deleteNode(head, 20);
    addLast(head, 11);
    addAfter(head, 11, 13);
    addBefore(head, 13, 17);
    addLast(head, -1);
    addLast(head, -2);
    addFirst(head, -100);
    output(head);
//    cout << '\n';
//    cout << calcSum(head) << '\n';
//    cout << countList(head) << '\n';
//    cout << countEven(head) << '\n';
//    outputLarger(head);
    cout << '\n';
//    deleteBefore(head, 10);
    deleteAfter(head, 10);
}
