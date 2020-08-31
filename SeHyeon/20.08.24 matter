#include <iostream>
using namespace std;

template<typename T>
class BinaryTree;

template<typename T>
class Node {
    friend class BinaryTree<T>;
    Node* left;
    Node* right;
    T data;
public:
    Node(T data = 0) : right(NULL), left(NULL), data(data) {};
};

template<typename T>
class BinaryTree {
    Node<T>* node;
public:
    BinaryTree(T data = 0) : node(new Node<T>(data)) {};
    void printTree(Node<T>* root) {
        if (root == NULL)    return;
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
    void printWantPart(Node<T>* root, T small, T large);
    Node<T>* getRoot() { return node; }
    Node<T>* appendTree(Node<T>* root, T data);
};

template<typename T>
void BinaryTree<T>::printWantPart(Node<T>* root, T small, T large) {
    /*if (root == NULL)   return;
    if (root->data > small&& root->data < large) cout << root->data << " ";
    if (root->left->data > small)   printWantPart(root->left, small, large);
    if (root->right->data < large)  printWantPart(root->right, small, large);*/

    if (root == NULL)    return;
    if (root->data > small&& root->data < large) cout << root->data << " ";
    printWantPart(root->left, small, large);
    printWantPart(root->right, small, large);
}
template<typename T>
Node<T>* BinaryTree<T>::appendTree(Node<T>* root, T data) {
    if (root->data > data) {
        if (root->left == NULL) {
            Node<T>* tmp = new Node<T>(data);
            root->left = tmp;
            return root;
        }
        root->left = appendTree(root->left, data);
    }
    else {
        if (root->right == NULL) {
            Node<T>* tmp = new Node<T>(data);
            root->right = tmp;
            return root;
        }
        root->right = appendTree(root->right, data);
    }
    return root;
}

int main() {
    BinaryTree<int>* bt = new BinaryTree<int>(5);
    Node<int>* root = bt->getRoot();
    root = bt->appendTree(root, 3);
    root = bt->appendTree(root, 9);
    root = bt->appendTree(root, 7);
    root = bt->appendTree(root, 10);
    root = bt->appendTree(root, 8);
    bt->printTree(root);
    putchar('\n');
    bt->printWantPart(root, 6, 10);
}
