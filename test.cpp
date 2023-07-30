//
// Created by longdnk on 1/15/2023.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key;
	Node *next;
	
	Node() = default;
	
	explicit Node(int x) : key(x), next(nullptr) { }
};

struct List {
	Node *head;
	Node *tail;
	
	List() : head(nullptr), tail(nullptr) { }
};

void addHead(List &ls, int k) {
	Node *p = new Node(k);
	if (ls.head == nullptr) {
		ls.head = ls.tail = p;
	}
	else {
		p->next = ls.head;
		ls.head = p;
	}
	ls.tail->next = ls.head;
}

void addLast(List &ls, int k) {
	Node *p = new Node(k);
	if (ls.head == nullptr) {
		ls.head = ls.tail = p;
	}
	else {
		ls.tail->next = p;
		ls.tail = p;
	}
	ls.tail->next = ls.head;
}

Node *searchNode(List ls, int k) {
	Node *p = ls.head;
	do {
		if (p->key == k) {
			return p;
		}
		p = p->next;
	} while (p != ls.head);
	return nullptr;
}

Node *findElement(List ls, Node *&prev, int k) {
	Node *p = ls.head;
	do {
		if (p->key == k) {
			return p;
		}
		prev = p;
		p = p->next;
	} while (p != ls.head);
	return nullptr;
}

bool addAfter(List &ls, int v, int k) {
	Node *q = searchNode(ls, v);
	if (q == nullptr) {
		return false;
	}
	Node *p = new Node(k);
	p->next = q->next;
	q->next = p;
	return true;
}

bool addBefore(List &ls, int v, int k) {
	Node *prev = nullptr;
	Node *q = findElement(ls, prev, v);
	if (q == nullptr) {
		return false;
	}
	Node *p = new Node(k);
	if (prev == nullptr) {
		addHead(ls, k);
	}
	else {
		p->next = prev->next;
		prev->next = p;
	}
	return true;
}

void print(List ls) {
	Node *p = ls.head;
	do {
		cout << p->key << ' ';
		p = p->next;
	} while (p != ls.head);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	List ls;
//    addHead(ls, 10);
//    addHead(ls, 20);
//    addHead(ls, 30);
	addLast(ls, 10);
	addLast(ls, 20);
	addLast(ls, 30);
//	addBefore(ls, 20, 40);
//	addAfter(ls, 30, 40);
//    cout << search(ls, 100) << '\n';
	print(ls);
}
