#include<bits/stdc++.h>

#define null NULL
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

void init(Node *&head) {
    head = null;
}

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = p->prev = null;
    return p;
}

void addFirst(Node *&head, int x) {
    Node *p = createNode(x);
    p->next = head;
    if (head != null) {
        head->prev = p;
    }
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = createNode(x);
    p->next = null;
    if (head == null) {
//		addFirst(head, x)
        p->prev = null;
        head = p;
    } else {
        Node *last = head;
        while (last->next != null) {
            last = last->next;
        }
        last->next = p;
        p->prev = last;
    }
}

void addAfter(Node *&head, int v, int x) {
    Node *q = head;
    Node *last = head;
    while (q != null && q->value != v) {
        q = q->next;
    }
    while (last->next != null) {
        last = last->next;
    }
    if (q != null) {
        if (q == last) {
            addLast(head, x);
        } else {
            Node *p = createNode(x);
            p->next = q->next;
            q->next->prev = p;
            q->next = p;
            p->prev = q;
        }
    }
}

void deleteFirst(Node *&head) {
    if (head != null) {
        Node *p = head;
        if (p->next == null) {
            head = null;
        } else {
            head = p->next;
            p->next->prev = null;
            p->next = null;
        }
        delete p;
    }
}

void deleteLast(Node *&head) {
    if (head != null) {
        Node *prev = null;
        Node *last = head;
        if (last->next == null) {
            head = null;
        } else {
            while (last->next != null) {
                prev = last;
                last = last->next;
            }
            prev->next = null;
            delete last;
        }
    }
}

void deleteNode(Node *&head, int v) {
    if (head != null) {
        Node *prev = null;
        Node *p = head;
        if (p->next == null) {
            head = null;
        } else {
            while (p != null && p->value != v) {
                prev = p;
                p = p->next;
            }
            if (p != null) {
                if (prev == null) {
                    deleteFirst(head);
                } else {
//					cout << prev->value << ' ' << p->next->value << '\n';
                    if (p->next == null) {
                        deleteLast(head);
                    } else {
                        prev->next = p->next;
                        p->next->prev = prev;
                        p->next = null;
                        delete p;
                    }
                }
            }
        }
    }
}

void output(Node *head) {
    while (head != null) {
        cout << head->value << ' ';
        head = head->next;
    }
    cout << '\n';
}

void printLast(Node *head) {
    if (head != null) {
        Node *last = head;
        while (last->next != null) {
            last = last->next;
        }
        while (last != null) {
            cout << last->value << ' ';
            last = last->prev;
        }
        cout << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *head;
    init(head);
//	addFirst(head, 10);
//	addFirst(head, 20);
//	addFirst(head, 30);
    addLast(head, 10);
    addLast(head, 20);
    addLast(head, 30);
    addLast(head, 40);
    addLast(head, 50);
    addAfter(head, 10, 60);
//	output(head);
    printLast(head);
    deleteNode(head, 60);
//	output(head);
    printLast(head);
}