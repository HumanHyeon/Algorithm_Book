#include<iostream>
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
void preOrder(Node *node); //내용물의 확인을 위한 전위순회

int main() {
	int item = 0;
	Node *startPnt = NULL;
	cout << "랜덤으로 10 개의 이진트리 원소 생성\n";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		item = rand()%100;
		insertnode(&startPnt,item);
		cout << "입력 : " << item << "\n";
	}
	cout << "------전위순환 출력-------\n";
		preOrder(startPnt);
	
	getchar();
	return 0;
}
void insertnode(Node **node, int value) //**node : node 포인터의 메모리 주소.
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
	else if (value > (*node)->data) //생각보다 간단했는데 여기 부등호 방향만 바꾸니까 됐다,,
		insertnode(&((*node)->leftnode), value);
	else if (value <(*node)->data)
		insertnode(&((*node)->rightnode), value);
	else
		cout << "중복\n";
};
void preOrder(Node *node) {
	if (node != NULL) {
		cout << node->data << " ";
		preOrder(node->leftnode);
		preOrder(node->rightnode);
	}
}
