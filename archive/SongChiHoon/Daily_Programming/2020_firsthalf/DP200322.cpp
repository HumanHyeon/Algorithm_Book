// 링크드 리스트(linked list)의 머리 노드(head node)와 정수 N이 주어지면, 끝에서 N번째 노드(node)를 제거하고 머리 노드(head node)를 리턴하시오.

// 단, 리스트를 한번만 돌면서 풀어야합니다. N은 리스트 길이보다 크지 않습니다.

// Given a head node of a singly linked list, remove the Nth last element and return the head node.



// 예제)

// Input: 1->2->3->4->5, N=2

// Output: 1->2->3->5



// Input: 1->2->3, N=3

// Output: 2->3



// Input: 1, N=1

// Output: null

#include <iostream>
using namespace std;

typedef int datatype;

typedef struct linked_list
{
    datatype data;
    struct linked_list* link;
} node;

node* addNode(int n){
    node *addingnode = new node;

    addingnode->data = n;
    addingnode->link = NULL;

    return addingnode;
}

node* delNode(node* targetnode, int target, int casenum){
    node* delNode = targetnode -> link;  node* predelnode = targetnode;

    for (int i = 0; i < casenum - target; i++)
    {
        delNode = delNode -> link;
        predelnode = predelnode -> link;
    }

    predelnode -> link = delNode -> link;    
}

int main(){
    int casenum, input, target;
    node* tmp = NULL;   node* result = NULL;    node* head = NULL;  node* mainnode = NULL;
    
    head -> link = mainnode;

    cout << "입력 갯수를 입력하시오 : ";
    cin >> casenum;

    cout << "Input : ";

    for (int i = 0; i < casenum; i++)
    {
        cin >> input;
        mainnode = addNode(input);
        mainnode = mainnode -> link;
    }

    cout << "N = ";    cin >> target;

    delNode(head, target, casenum);

    for (node* i = head -> link; i != NULL; i = i -> link)
    {
        cout << i -> data;
        if (i -> link != NULL)
        {
            cout << "->";
        }
    }
    
    return 0;
}