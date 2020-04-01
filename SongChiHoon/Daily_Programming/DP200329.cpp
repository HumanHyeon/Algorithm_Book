// 두개의 정렬된(sorted) 정수 링크드리스트(linked list)가 주어지면, 두 리스트를 합친 정렬된 링크드리스트를 만드시오.

// Given two sorted integer linked lists, merge the two linked lists. Merged linked list must also be sorted.



// 예제)

// Input: 1->2->3, 1->2->3

// Output: 1->1->2->2->3->3



// Input: 1->3->5->6, 2->4

// Output: 1->2->3->4->5->6

#include <iostream>
using namespace std;

typedef int datatype;

typedef struct linked_list
{
    datatype data;
    struct linked_list* link;
} node;

typedef struct
{
    node *newnode1;
    node *newnode2;
} tmp;

node* merge(node *newnode1, node *newnode2){
    node *endvalue = NULL;

    if(newnode1 == NULL)    return newnode2;
    else if(newnode2 == NULL) return newnode1;

    if (newnode1 -> data < newnode2 -> data)
    {
        endvalue = newnode1;
        endvalue->link = merge(newnode1->link, newnode2);
    }
    else
    {
        endvalue = newnode2;
        endvalue->link = merge(newnode1, newnode2->link);
    }
    
    return endvalue;
}

tmp partition(node *list, int k){
    node *point;
    tmp result;
    node *newnode1, *newnode2;

    int i;

    point = list;
    newnode1 = list;

    for (int i = 0; i < k - 1; i++)
    {
        point = point->link;
    }

    newnode2 = point->link;

    point->link = NULL;

    result.newnode1 = newnode1;
    result.newnode2 = newnode2;

    return result;    
}

//node-making function.
node* addNode(int n){
    node *newnode;

    newnode = new node;

    newnode->data = n;
    newnode->link = NULL;

    return newnode;
}
//merging two other linked list
void mergeSort(node **L, int k){
    node *newnode1 = NULL;  node *newnode2 = NULL;
    tmp tmp;
    
    node *result;

    if (k > 1 && *L != NULL)
    {
        tmp = partition(*L, k/2);
        newnode1 = tmp.newnode1;
        newnode2 = tmp.newnode2;

        mergeSort(&newnode1, k/2);
        mergeSort(&newnode2, (int)((k/2.0) + 0.5));

        *L = merge(newnode1, newnode2);
    }
    
}

int main(){
    node *head; node *tmp;  node *output;
    int casenum, t;

    head = new node;
    head->link = NULL;

    cout << "배열 정수 갯수 입력 : ";
    cin >> casenum;

    for (int i = 0; i < casenum; i++)
    {
        cin >> t;
        tmp->link = addNode(t);
        tmp = tmp -> link;
    }
    
    mergeSort(&head->link, casenum);

    output = head->link;

    while (output != NULL)
    {
        cout << " " << output->data;
        output = output->link;
    }
    
    cout << endl;

}



// node *head = NULL;  node *tail = NULL;  node *cur = NULL;
// // head는 시작 노드, tail은 끝 노드, cur은 출력 지정 노드
// node getInput(node *NODE, int num){

//     int readData, count;
//     do
//     {
//         cout << "Input : ";
//         cin >> readData;
//         if (readData > 0)
//         {
//             count++;
//         }
//         else
//         {
//             break;
//         }
//         NODE = new node;
//         NODE->data = readData;
//         NODE->link = NULL;

//         if (head == NULL)   head = NODE;
//         else    tail->link = NODE;
        
//         tail = NODE;
//     } while (readData == NULL);
// }