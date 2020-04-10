#include <cstdio>
#include <cstdlib>
#pragma warning(disable : 6011)
#pragma warning(disable : 28182)

typedef int dataType;	//#define dataType int

typedef struct linked_list {
	dataType data;
	struct linked_list* tail;
}node;

void removeNode(node* head, int index) {
	node* remove = head->tail;
	node* previous = head;
	for (int i = 0; i < index - 1; i++, remove = remove->tail, previous = previous->tail);

	previous->tail = remove->tail;
}

void reverseRemoveNode(node* head, int index) {
	int size = -1;
	for (node* tmp = head; tmp != NULL; tmp = tmp->tail)   size++;

	node* remove = head->tail;
	node* previous = head;
	if (index != size)
		for (int i = 0; i < size - index; i++, remove = remove->tail, previous = previous->tail);
	
	previous->tail = remove->tail;
}

void displayNode(node* head) 
{
	head = head->tail;
	for (node* tmp = head; tmp != NULL; tmp = tmp->tail) {
		printf("%d ", tmp->data);
	}
}

int main() {
	node* head = (node*)malloc(sizeof(node));

	node* n1 = (node*)malloc(sizeof(node));
	head->tail = n1;
	n1->data = 10;

	node* n2 = (node*)malloc(sizeof(node));
	n1->tail = n2;
	n2->data = 20;

	node* n3 = (node*)malloc(sizeof(node));
	n2->tail = n3;
	n3->data = 30;

	node* n4 = (node*)malloc(sizeof(node));
	n3->tail = n4;
	n4->data = 40;

	node* n5 = (node*)malloc(sizeof(node));
	n4->tail = n5;
	n5->data = 50;
	n5->tail = NULL;

	int input;	scanf_s("%d", &input);

	reverseRemoveNode(head, input);
	//removeNode(head, input);
	displayNode(head);

	free(n5), free(n4), free(n3), free(n2), free(n1);
}
