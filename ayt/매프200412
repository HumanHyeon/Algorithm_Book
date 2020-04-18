#include <iostream>
using namespace std;

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 4,NULL,NULL };
TreeNode n2 = { 2,&n1,NULL };
TreeNode n3 = { 5,NULL,NULL };
TreeNode n4 = { 6,NULL,NULL };
TreeNode n5 = { 3,&n3,&n4 };
TreeNode n6 = { 1,&n2,&n5 };
TreeNode* root = &n6;
//            1
//       2          3
//   4          5       6

void display(TreeNode* root) {
	if (root) {	
		cout << root->data << " ";
		display(root->left);
		display(root->right);
	}
}

//            1
//       3          2
//   6       5          4
void reverse(TreeNode* root) {
	if (root) {
		cout << root->data << " ";
		reverse(root->right);
		reverse(root->left);
	}
}

int main() {
	display(root);
	cout << endl;
	reverse(root);

	return 0;
}
