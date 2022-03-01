#include <iostream>
#pragma warning(disable : 6011)
using namespace std;

#define var int

typedef struct node {
	var data;
	struct node* left;
	struct node* right;
}Node;

Node* root = NULL;
Node* tmp = (Node*)malloc(sizeof(Node));

Node* createNode(Node* root, var value) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->data = value;
		root->left = root->right = NULL;
	}
	else {
		if (root->data > value)
			root->left = createNode(root->left, value);
		else
			root->right = createNode(root->right, value);
	}
	return root;
}

void changeNode(Node* root) {
	//if (root == NULL)	return;
	tmp->left = tmp->right = NULL;
	tmp->left = root->left;
	root->left = root->right;
	root->right = tmp->left;

	if(root->left != NULL)	changeNode(root->left);
	if(root->right != NULL) changeNode(root->right);
}

void printNode(Node* root) {
	if (root == NULL)	return;

	cout << root->data << " ";
	printNode(root->left);
	printNode(root->right);
}

int main() {
	root = createNode(root, 6);
	/*for (int i = 1; i < 10; i++)
		root = createNode(root, i);*/

	createNode(root, 5);
	createNode(root, 7);
	createNode(root, 3);
	createNode(root, 2);
	createNode(root, 4);
	createNode(root, 8);
	createNode(root, 10);

	printNode(root);
	putchar('\n');
	changeNode(root);
	printNode(root);
}                                       
