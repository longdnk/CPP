#include<bits/stdc++.h>

#define null NULL
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *createNode(int x) {
    Node *p = new Node;
    p->value = x;
    p->next = null;
    return p;
}

void init(Node *&head) {
    head = null;
}

void addFirst(Node *&head, int x) {
    Node *p = createNode(x);
    p->next = head;
    head = p;
}

void addLast(Node *&head, int x) {
    Node *p = createNode(x);
    if (head == null) {
        head = p;
    }
    else {
        Node *last = head;
        while (last->next != null) {
            last = last->next;
        }
        last->next = p;
    }
}

void addAfter(Node *&head, int v, int x) {
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

int getListSize(Node *head) {
    int size = 0;
    while (head != null) {
        ++size;
        head = head->next;
    }
    return size;
}

void addAfterK(Node *&head, int k, int x) {
    if (k <= 0 || k > getListSize(head) || head == null) {
        return;
    }
    else {
        --k;
        int cnt = 0;
        Node *p = createNode(x);
        Node *q = head;
        while (q != null && cnt < k) {
            ++cnt;
            q = q->next;
        }
        if (q != null) {
            p->next = q->next;
            q->next = p;
        }
    }
}

void deleteFirst(Node *&head) {
    if (head != null) {
        Node *p = head;
        head = p->next;
        p->next = null;
        delete p;
    }
}

void deleteLast(Node *&head) {
    if (head != null) {
        Node *prev = null;
        Node *last = head;
        while (last->next != null) {
            prev = last;
            last = last->next;
        }
        if (prev == null) {
            Node *tmp = head;
            head = tmp->next;
            tmp->next = null;
            delete tmp;
        }
        else {
            prev->next = null;
            delete last;
        }
    }
}

void deleteNode(Node *&head, int x) {
    if (head != null) {
        Node *prev = null;
        Node *p = head;
        while (p != null && p->value != x) {
            prev = p;
            p = p->next;
        }
        if (p != null) {
            if (prev == null) {
                Node *tmp = head;
                head = tmp->next;
                tmp->next = null;
                delete tmp;
            }
            else {
                prev->next = p->next;
                p->next = null;
                delete p;
            }
        }
    }
}

void deleteNodeAtK(Node *&head, int k) {
    if (k <= 0 || k > getListSize(head) || head == null) {
        return;
    }
    else {
        Node *prev = null;
        Node *p = head;
        --k;
        int cnt = 0;
        while (p != null && cnt < k) {
            ++cnt;
            prev = p;
            p = p->next;
        }
        if (p != null) {
            if (prev == null) {
                Node *tmp = head;
                head = tmp->next;
                tmp->next = null;
                delete tmp;
            }
            else {
                prev->next = p->next;
                p->next = null;
                delete p;
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

void deleteNodeHaveValue(Node *&head, int x) {
    Node *p = head;
    while (p != null) {
        deleteNode(head, x);
        p = p->next;
    }
}

void removeDuplicate(Node *&head) {
    Node *p = head;
    int cnt[109] = {};
    while (p != null) {
        ++cnt[p->value];
        p = p->next;
    }
    Node *tmp = head;
    int *ar = new int[getListSize(head)];
    int index = 0;
    while (tmp != null) {
        if (cnt[tmp->value] > 1) {
            ar[index] = tmp->value;
            ++index;
        }
        tmp = tmp->next;
    }
    for (int i = 0; i < index; ++i) {
        deleteNode(head, ar[i]);
    }
//    p = head;
//    vector<int> ar;
//    while (p != null) {
//        if (cnt[p->value] > 1) {
//            ar.emplace_back(p->value);
//        }
//        p = p->next;
//    }
//    for (auto item: ar) {
//        deleteNode(head, item);
//    }
}

int getLength(const char *s) {
    int cnt = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        ++cnt;
    }
    return cnt;
}

int countUpper(const char *s) {
    int cnt = 0;
    for (int i = 0; i < getLength(s); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ++cnt;
        }
    }
    return cnt;
}

int countFreq(const char *s, const char *p) {
    int cnt = 0;
    int N = getLength(s);
    int M = getLength(p);
    for (int i = 0; i <= N - M; ++i) {
        int j;
        for (j = 0; j < M; ++j) {
            if (s[i + j] != p[j]) {
                break;
            }
        }
        if (j == M) {
            ++cnt;
        }
    }
    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    Node *head;
//    init(head);
//    addFirst(head, 10);
//    addFirst(head, 20);
//    addFirst(head, 30);
//    addFirst(head, 40);
//    addLast(head, 10);
//    addLast(head, 20);
//    addLast(head, 30);
//    addAfter(head, 30, 40);
//    output(head);
//    deleteNode(head, 10);
//    deleteNodeAtK(head, 0);
//deleteNodeHaveValue(head, 10);
//    removeDuplicate(head);
//    output(head);
}