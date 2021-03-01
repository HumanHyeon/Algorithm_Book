#include <iostream>
using namespace std;
#define type int
#define LISTSIZE sizeof(list)/sizeof(list[0])

typedef struct node {
	type data;
	struct node* next;
}NODE;

typedef struct {
	NODE* N1;
	NODE* N2;
}TMP;

NODE* addNode(type input) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->next = NULL;
	
	return newNode;
}

void createNode(NODE* head, type *input, int size) {
	NODE* tmp = head;
	for (int i = 0; i < size; i++) {
		tmp->next = addNode(input[i]);
		tmp = tmp->next;
	}
}

void printNode(NODE* head) {
	NODE* tmp = head;

	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	putchar('\n');
}

TMP partition(NODE* List, int listSize) {
	NODE* point = List;
	NODE* node1 = List, * node2;
	TMP result;

	for (int i = 0; i < listSize - 1; i++) 
		point = point->next;
	
	node2 = point->next;
	point->next = NULL;
	result.N1 = node1;
	result.N2 = node2;

	return result;
}

NODE* merge(NODE* node1, NODE* node2) {
	NODE* result = NULL;

	if (node1 == NULL)	return node2;
	if (node2 == NULL)	return node1;

	if (node1->data < node2->data) {
		result = node1;
		result->next = merge(node1->next, node2);
	}
	if (node1->data >= node2->data) {
		result = node2;
		result->next = merge(node1, node2->next);
	}

	return result;
}

void mergeSort(NODE** List, int listSize) {
	NODE *node1 = NULL, *node2 = NULL;
	TMP tmp;

	if (listSize >= 1 && *List != NULL) {
		tmp = partition(*List, listSize / 2);
		node1 = tmp.N1;
		node2 = tmp.N2;

		mergeSort(&node1, listSize / 2);
		mergeSort(&node2, (int)((listSize / 2) + 0.5));

		*List = merge(node1, node2);
	}
}
 
int main() {
	type list[] = {7, 9, 6, 8, 1, 2, 5, 3, 0, 0, 1, 2, 3};
	//type list[] = { 'a', 'd', 'c', 'f', 'z', 'k' };
	NODE* head = (NODE*)malloc(sizeof(NODE));

	createNode(head, list, LISTSIZE);
	mergeSort(&head->next, LISTSIZE);
	printNode(head->next);
}
