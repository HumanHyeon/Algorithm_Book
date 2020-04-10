// 두개의 정렬된(sorted) 정수 링크드리스트(linked list)가 주어지면, 두 리스트를 합친 정렬된 링크드리스트를 만드시오.

// Given two sorted integer linked lists, merge the two linked lists. Merged linked list must also be sorted.



// 예제)

// Input: 1->2->3, 1->2->3

// Output: 1->1->2->2->3->3



// Input: 1->3->5->6, 2->4

// Output: 1->2->3->4->5->6

#include <iostream>
using namespace std;

typedef int datatype;   //set linked list data-type

//set node, linked_list
typedef struct linked_list
{
    datatype data;
    struct linked_list* link;
} node;

//linked_list merging data_structure
typedef struct
{
    node *newnode1;
    node *newnode2;
} tmp;

//only merging function.
//make two different list into one sorted list.
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

//dividing function.
//one list divided into two semi list and return it.
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
//merging two other linked list. recursive.
//L is list starting address, k is list size.
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
    int casenum, input;

    head = new node;
    head->link = NULL;

    cout << "배열 정수 갯수 입력 : ";
    cin >> casenum;

    for (int i = 0; i < casenum; i++)
    {
        cin >> input;
        tmp->link = addNode(input);
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

    return 0;
}