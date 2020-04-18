#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Node {
public:
	Node *leftnode;
	int data;
	Node *rightnode;
};

void insertnode(Node **node, int value);
void preOrder(Node *node); //���빰�� Ȯ���� ���� ������ȸ

int main() {
	int item = 0;
	Node *startPnt = NULL;
	cout << "�������� 10 ���� ����Ʈ�� ���� ����\n";
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		item = rand()%100;
		insertnode(&startPnt,item);
		cout << "�Է� : " << item << "\n";
	}
	cout << "------������ȯ ���-------\n";
		preOrder(startPnt);
	
	getchar();
	getchar();
	return 0;
}
void insertnode(Node **node, int value) //**node : node �������� �޸� �ּ�.
{
	if (*node == NULL) {
		*node = (Node*)malloc(sizeof(Node));
		if (*node != NULL) {
			(*node)->data = value;
			(*node)->leftnode = NULL;
			(*node)->rightnode = NULL;
		}
		else
			cout << "\n" << value << "not inserted. No memory available.\n";
	}
	else if (value > (*node)->data)
		insertnode(&((*node)->leftnode), value);
	else if (value <(*node)->data)
		insertnode(&((*node)->rightnode), value);
	else
		cout << "�ߺ�\n";
};
void preOrder(Node *node) {
	if (node != NULL) {
		cout << node->data << " ";
		preOrder(node->leftnode);
		preOrder(node->rightnode);
	}
}
