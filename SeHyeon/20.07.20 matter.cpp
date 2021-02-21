#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename B>
class BinaryTree;

template<typename A>
class Node {
    friend class BinaryTree<A>;
private:
    Node* left;
    Node* right;
    A data;
public:
    Node(A data = 0, Node* left = NULL, Node* right = NULL) 
        : data(data), left(left), right(right){}
}; 

template<typename B>
class BinaryTree {
private:
    Node<B>* root;
public:
    BinaryTree(B data = 0) : root(new Node<B>(data)) {};
    Node<B>* getRoot() { return root; };
    void printTree(Node<B>* root);
    Node<B>* appendTree(Node<B>* root, B data);
    Node<B>* findMinTree(Node<B>* root);
    Node<B>* searchTree(Node<B>* root, B data);
    Node<B>* deleteTree(Node<B>* root, B data);
    void printLevelTraversal(Node<B>* root);
    void solution(Node<B>* root);
};

template<typename B>
void BinaryTree<B>::printTree(Node<B>* root) {
    if (root == NULL)    return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

template<typename B>
Node<B>* BinaryTree<B>::appendTree(Node<B>* root, B data) {
    if (root == NULL) {
        root =  new Node<B>(data);
        root->left = root->right = NULL;
        root->data = data;
        return root;
    }
    else {
        if (root->data > data) root->left = appendTree(root->left, data);
        else root->right = appendTree(root->right, data);
    }
    return root;
}

template<typename B>
Node<B>* BinaryTree<B>::findMinTree(Node<B>* root) {
    Node<B>* min = root;
    while (min->left != NULL)    min = min->left;
    return min;
}

template<typename B>
Node<B>* BinaryTree<B>::searchTree(Node<B>* root, B data) {
    if (root == NULL)    return NULL;
    if (root->data == data)  return root;
    else if (root->data > data) return searchTree(root->left, data);
    else return searchTree(root->right, data);
}

template<typename B>
Node<B>* BinaryTree<B>::deleteTree(Node<B>* root, B data) {
    if (root == NULL)    return NULL;

    Node<B>* tNode = NULL;
    if (root->data > data)   root->left = deleteTree(root->left, data);
    else if (root->data < data)  root->right = deleteTree(root->right, data);
    else if (root->data == data) {
        if (root->right != NULL && root->left != NULL) {
            tNode = findMinTree(root->right);
            root->data = tNode->data;
            root->right = deleteTree(root->right, tNode->data);
        }
        else {
            tNode = (root->left == NULL) ? root->right : root->left;
            free(root);
            return tNode;
        }
    }
    return root;
}

template<typename B>
void BinaryTree<B>::printLevelTraversal(Node<B>* root) {
    queue<Node<B>*> circuit;   //큐 생성 및 초기화
    if (root)    circuit.push(root);    //큐에 루트 노드 삽입
    while (!circuit.empty()) {  //큐가 empty일 때까지 반복
        Node<B>* tmp = circuit.front(); //추출
        circuit.pop();                  //추출
        cout << tmp->data << " ";       //방문
        if (tmp->left) circuit.push(tmp->left);     //왼쪽 자식 있을 시 삽입
        if (tmp->right) circuit.push(tmp->right);   //오른쪽 자식 있을 시 삽입
    }
    putchar('\n');
}

template<typename B>
void BinaryTree<B>::solution(Node<B>* root) {
    queue<Node<B>*> circuit;   
    vector<B> input;
  
    if (root)   circuit.push(root);
    while (!circuit.empty()) {  
        Node<B>* tmp = circuit.front();
        circuit.pop();          
        
        if (tmp == NULL) {
            input.push_back(NULL);
            continue;
        }

        input.push_back(tmp->data);
        if (tmp->left) circuit.push(tmp->left);
        else circuit.push(NULL);
        if (tmp->right) circuit.push(tmp->right);   
        else circuit.push(NULL);
    }

    bool flag = true;
    int limit = 1, count = 0, index = -1;
    for (int i = 0; i < input.size(); i++) {
        if (count == limit) {
            limit *= 2, count = 0;
            flag = !flag;
            index = i + limit - 1;
        }
        if (flag) {
            if (input[i] != NULL)  cout << input[i] << " ";
        }
        else
            if(input[index] != NULL)    cout << input[index--] << " ";
            else index--;
        count++;
    }
    putchar('\n');
}

int main() {
    BinaryTree<int>* BST = new BinaryTree<int>(5);
    Node<int>* root = BST->getRoot();

    int arr[] = { 3, 7, 2, 4, 6, 8 };

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        root = BST->appendTree(root, arr[i]);


    BST->solution(root);
}
