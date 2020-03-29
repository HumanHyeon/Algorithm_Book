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

typedef struct NODE
{
    int data;
    int order;
    struct NODE *link;
} NODE;

int main()
{
    int input, target, N;  int series = 0;

    cout << "Input: ";
    do
    {
        series += 1;
        cin >> input;
        if (input == NULL)
        {
            break;
        }
        NODE *new_node = new NODE;
        new_node -> data = input;
        new_node -> order = series;

    } while (true);

    cout << "N=";
    cin >> N;
    target = series - N + 1;
    delete new_node[target];
    
    

}