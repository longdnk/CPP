//
// Created by longdnk on 12/20/2022.
//
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key;
	Node *next;
	Node() = default;
	Node(int x) : key(x), next(NULL) { }
};

struct List {
	Node *head;
	Node *tail;
	List() : head(NULL), tail(NULL) { }
};

void addHead(List *&ls, int k) {
	Node *p = new Node(k);
	if (ls->head == NULL) {
		ls->head = ls->tail = p;
	}
	else {
		p->next = ls->head;
		ls->head = p;
	}
	ls->tail->next = ls->head;
}

void addLast(List *&ls, int k) {
	Node *p = new Node(k);
	if (ls->head == NULL) {
		ls->head = ls->tail = p;
	}
	else {
		ls->tail->next = p;
		ls->tail = p;
	}
	ls->tail->next = ls->head;
}

Node *searchNode(List *ls, int k) {
	Node *p = ls->head;
	do {
		if (p->key == k) {
			return p;
		}
		p = p->next;
	} while (p != ls->head);
	return NULL;
}

bool addAfter(List *&ls, int v, int k) {
	Node *q = searchNode(ls, v);
	if (q == NULL) {
		return false;
	}
	Node *p = new Node(k);
	p->next = q->next;
	q->next = p;
	if (q == ls->tail) {
		ls->tail = ls->tail->next;
		ls->tail->next = ls->head;
	}
	return true;
}

Node *findElement(List *ls, Node *&prev, int x) {
	Node *p = ls->head;
	do {
		if (p->key == x) {
			return p;
		}
		prev = p;
		p = p->next;
	} while (p != ls->head);
	return NULL;
}

bool addBefore(List *&ls, int v, int k) {
	Node *prev = NULL;
	Node *q = findElement(ls, prev, v);
	if (q == NULL) {
		return false;
	}
	if (prev == NULL) {
		addHead(ls, k);
	}
	else {
		Node *p = new Node(k);
		p->next = prev->next;
		prev->next = p;
	}
	return true;
}

bool deleteHead(List *&ls) {
	if (ls->head != NULL) {
		Node *p = ls->head;
		ls->head = p->next;
		p->next = NULL;
		delete p;
		if (ls->head == NULL) {
			ls->tail = NULL;
		}
		else {
			ls->tail->next = ls->head;
		}
		return true;
	}
	return false;
}

bool deleteLast(List *&ls) {
	if (ls->head != NULL) {
		Node *last = ls->head;
		Node *prev = NULL;
		do {
			prev = last;
			last = last->next;
		} while (last != ls->tail);
		prev->next = ls->head;
		ls->tail = prev;
		if (ls->tail == NULL) {
			ls->head = NULL;
		}
		return true;
	}
	return false;
}

bool deleteNode(List *&ls, int k) {
	if (ls->head != NULL) {
		Node *prev = NULL;
		Node *p = findElement(ls, prev, k);
		bool flag = false;
		if (p != NULL) {
			if (prev == NULL) {
				return deleteHead(ls);
			}
			if (p == ls->tail) {
				ls->tail = prev;
			}
			prev->next = p->next;
			p->next = NULL;
			delete p;
			flag = true;
		}
		return flag;
	}
	return false;
}

int getListSize(List *ls) {
	Node *p = ls->head;
	int size = 0;
	do {
		++size;
		p = p->next;
	} while (p != ls->head);
	return size;
}

bool deleteNodeAtK(List *&ls, int k) {
	if (k <= 0 || k > getListSize(ls) || ls->head == NULL) {
		return false;
	}
	Node *p = ls->head;
	Node *prev = NULL;
	do {
		prev = p;
		p = p->next;
		--k;
	} while (p != ls->head && k > 1);
	if (prev == ls->head) {
		return deleteHead(ls);
	}
	if (p == ls->tail) {
		ls->tail = prev;
	}
	prev->next = p->next;
	p->next = NULL;
	delete p;
	return true;
}

void output(List *ls) {
	Node *p = ls->head;
	do {
		cout << p->key << ' ';
		p = p->next;
	} while (p != ls->head);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	List *ls = new List;
	// addHead(ls, 10);
	// addHead(ls, 20);
	// addHead(ls, 30);
	addLast(ls, 10);
	addLast(ls, 20);
	addLast(ls, 30);
	addAfter(ls, 30, 40);
	// deleteLast(ls);
	// deleteHead(ls);
	// addBefore(ls, 10, 50);
	// deleteNode(ls, 40);
	deleteNodeAtK(ls, 1);
	output(ls);
}