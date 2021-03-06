#include <cstdio>
#include <cstdlib>
#pragma warning(disable : 6011)
#pragma warning(disable : 28182)

typedef int dataType;	//#define dataType int 

typedef struct link_data {
	struct linked_node* head;
	struct linked_node* tail;
}link;

typedef struct linked_node {
	dataType data;
	struct linked_node* next;
}node;

void createNode(link* L, int data) {
	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = data;
	newNode->next = NULL;

	if (L->head == NULL && L->tail == NULL)
		L->head = L->tail = newNode;
	else {
		L->tail->next = newNode;
		L->tail = newNode;
	}
}

void printNodes(link* L) {
	node* p = L->head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}

void combine(link* list1, link* list2, link* result) {
	node* n1 = list1->head;
	node* n2 = list2->head;

	while (true){
		if (n1 == NULL) {
			while (n2 != NULL) {
				createNode(result, n2->data);
				n2 = n2->next;
			}
			break;
		}
		if (n2 == NULL) {
			while (n1 != NULL) {
				createNode(result, n1->data);
				n1 = n1->next;
			}
			break;
		}

		if (n1->data > n2->data) {
			createNode(result, n2->data);
			n2 = n2->next;
		}
		else {
			createNode(result, n1->data);
			n1 = n1->next;
		}
	}
}

int main() {
	link* list1 = (link*)malloc(sizeof(link));
	list1->head = list1->tail = NULL;
	createNode(list1, 10);
	createNode(list1, 20);
	createNode(list1, 30);

	link* list2 = (link*)malloc(sizeof(link));
	list2->head = list2->tail = NULL;
	createNode(list2, 10);
	createNode(list2, 20);
	createNode(list2, 30);

	link* result = (link*)malloc(sizeof(link));
	result->head = result->tail = NULL;
	
	combine(list1, list2, result);
	printNodes(result);

	free(list1);	free(list2);	free(result);
}
