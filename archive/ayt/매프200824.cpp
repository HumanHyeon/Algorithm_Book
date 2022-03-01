#include <iostream>
using namespace std;

const int x = 5, y = 32;

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 3,NULL,NULL };
TreeNode n2 = { 12,NULL,NULL };
TreeNode n3 = { 7,&n1,&n2 };
TreeNode n4 = { 21,NULL,NULL };
TreeNode n5 = { 31,NULL,NULL };
TreeNode n6 = { 26,&n4,&n5 };
TreeNode n7 = { 18,&n2,&n6 };
TreeNode* root = &n7;
//             18
//       7            26
//   3      12    21       31

void findNode(TreeNode* root) {
    if (root == NULL)
        return;
    if (root->data > x&& root->data < y)
        cout << root->data << " ";

    findNode(root->left);
    findNode(root->right);
}

int main() {
    findNode(root);

    return 0;
}
