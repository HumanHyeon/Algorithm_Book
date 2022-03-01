#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode* link;
} ListNode;

void Sorting(ListNode* h1, ListNode* h2)
{
    int tmp[10];

    ListNode* p1 = h1; //���� ����Ʈ ����
    p1->link = h2;

    ListNode* p2 = h1; //���� ����Ʈ �����͸� �迭�� �߰�
    while (p2 != NULL)
    {
        int i = 0;
        tmp[i] = p2->data;
        p2 = p2->link;
        i++;
    }

    sort(tmp, tmp + sizeof(tmp) / sizeof(*tmp)); //�迭 ����

    ListNode* p3 = h1; //���ĵ� �����͸� ���� ����Ʈ �����Ϳ� ��ȯ
    while (p3 != NULL)
    {
        int i = 0;
        p3->data = tmp[i];
        p3 = p3->link;
        i++;
    }
}

void display(ListNode* h1)
{
    ListNode* p = h1;
    while (p != NULL) {
        cout << p->data << "->";
    }
    cout << endl;
}

int main()
{
    ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
    p1->data = 1;
    ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
    p1->link = p2;
    p2->data = 2;
    ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
    p2->link = p3;
    p3->data = 3;
    p3->link = NULL;

    ListNode* q1 = (ListNode*)malloc(sizeof(ListNode));
    q1->data = 1;
    ListNode* q2 = (ListNode*)malloc(sizeof(ListNode));
    q1->link = q2;
    q2->data = 2;
    ListNode* q3 = (ListNode*)malloc(sizeof(ListNode));
    q2->link = q3;
    q3->data = 3;
    q3->link = NULL;

    Sorting(p1, p2);

    display(p1);

    return 0;
}