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

int main(){
    // head는 시작 노드, tail은 끝 노드, cur은 출력 지정 노드
    node *head = NULL;  node *tail = NULL;  node *cur = NULL;

    node *newNode = NULL;

    int readData, count;
    //입력 받는 부분
    do
    {
        cout << "Input : ";
        cin >> readData >> "->";
        if (readData > 0)
        {
            count++;
        }
        else
        {
            break;
        }
        newNode = new node;
        newNode->data = readData;
        newNode->link = NULL;

        if (head == NULL)   head = newNode;
        else    tail->link = newNode;
        
        tail = newNode;
    } while (readData == NULL);

    if (head == NULL)
    {
        cout << "저장된 값 없음" << endl;
    }
    else
    {
        cur = head;
        cout << cur->data << "->";
        while (cur->link != NULL)
        {
            cur = cur->link;
            cout << cur->data << " ";
        }               
    }
}