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
#define maxnodenum 5;

typedef struct linked_list
{
    int data;
    struct linked_list* link;
} node;

void reconnect(node *linkedlist, int target)
{
    linkedlist[target-1].link = &linkedlist[target+1];

    cout << "Output : ";
    for (int i = 0; i < maxnodenum; i++)
    {
        cout << linkedlist[i].data;

        for (int j = 0; j < maxnodenum-1; j++)
        {
            cout << "->";
        }
    }
    return;
}

int main()
{
    int input, target;

    cout << "Input: ";
    node *linkedlist = new node[maxnodenum];    //연결리스트 동적 배열 생성

    // 리스트 배열들에 값 부여. :: 수정 필요. cin으로 받을 때 무조건 5개 다받야됨.
    for (int count = 0; count < maxnodenum; count++)
    {
        cin >> input;

        if (input == NULL)
        {
            break;
        }

        linkedlist[count].data = input;
    }

    // 리스트들 연결
    for (int count = 0; count < maxnodenum; count++)
    {
        linkedlist[count].link = &linkedlist[count+1];
    }

    cout << "N=";
    cin >> target;

    target = maxnodenum - target;   //목표값을 앞에서 오는 값으로 수정

    reconnect(linkedlist, target);

    delete[] linkedlist;

    return 0;
}