#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
};

Node* head = NULL;
Node* tail = NULL;
vector<int> sumZero;

void addNode(int data) {
    Node* newNode = NULL;

    newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;

}

void printNode() {
    if (head == NULL)
        cout << "No data" << endl;
    else {
        Node* cur = head;

        while (cur!= NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    cout << "\n";
}

void removeNode(int key) {
    if (head == NULL) {
        cout << "No data" << endl;
        return;
    }
        
    Node* cur = head;
    if (cur->data == key) {
        head = cur->next;
        free(cur);
        return;
    }
    while (cur->next != NULL) {
        if (cur->next->data == key) {
            Node* remNode = cur->next;
            if (remNode->next != NULL)
                cur->next = remNode->next;
            else
                cur->next = NULL;

            free(remNode);
            return;
        }
        cur = cur->next;
    }
}

void findSumZero() {
    Node* cur = head;
    Node* curNext = NULL;
    int sum = 0;

    while (cur != NULL) {
        curNext = cur->next;
        sum += cur->data;
        sumZero.push_back(cur->data);
        while (curNext != NULL) {
            sum += curNext->data;
            sumZero.push_back(curNext->data);
            if (sum == 0)
                break;        
            curNext = curNext->next;
        }
        if (sum == 0)
            break;
        sum = 0;
        sumZero.clear();
        cur = cur->next;
    }

    for (int i = 0; i < sumZero.size(); ++i)
        removeNode(sumZero[i]);
}

int main() {
    addNode(3);
    addNode(-5);
    addNode(5);
    addNode(1);
    addNode(2);
    addNode(3);

    printNode();
    findSumZero();
    printNode();

    return 0;
}
