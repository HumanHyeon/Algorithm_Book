#include <iostream>
using namespace std;

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

int nth_Node(ListNode* p1, int n) {
	ListNode* tmp = p1;
	int m = 0;

	while (tmp != NULL) {
		m++;
		tmp = tmp->link;
	}
	m = m - n;

	return m;
}

void remove_Node(ListNode* p1, int n) {
	int tmp[5];
	int n1 = n;
	ListNode* p = p1;
	while (p != NULL) {
		int i = 0;
		tmp[i] = p->data;
		i++;
		p = p->link;
	}

	tmp[n] = NULL;

	while (p1 != NULL) {
		int i = 0;
		p1->data = tmp[i];
		i++;
		p1 = p1->link;
	}
}

void display(ListNode* p1) {
	ListNode* p = p1;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}

int main() {
	int n = 2;

	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 1;
	ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 2;
	p1->link = p2;
	ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
	p3->data = 3;
	p2->link = p3;
	ListNode* p4 = (ListNode*)malloc(sizeof(ListNode));
	p4->data = 4;
	p3->link = p4;
	ListNode* p5 = (ListNode*)malloc(sizeof(ListNode));
	p5->data = 5;
	p4->link = p5;
	p5->link = NULL;

	n = nth_Node(p1, n);

	remove_Node(p1, n);

	display(p1);

	return 0;
}
