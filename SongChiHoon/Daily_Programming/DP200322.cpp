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

typedef struct linked_list
{
    int data;
    struct linked_list* link;
} linked_list;

int main()
{
    int *linkedlist[5];
    int input, target;

    cout << "Input: ";
    for (int count = 0; count < 5; count++)
    {
        cin >> input;
        linked_list *linkedlist[count] = new linked_list;
        linkedlist[count]
    }
    linked_list* head = new linked_list;


    cout << "N=";
    cin >> N;
    target = series - N + 1;
    delete n1[target];
    
    

}