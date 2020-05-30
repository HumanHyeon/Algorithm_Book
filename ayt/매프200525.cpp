#include <iostream>
#include <algorithm>
using namespace std;

typedef struct list {
	int data;
	struct list* link;
}list;

void sorting(list* p1) {
    int tmp[5];

    for (int i = 0; i < 5; i++) {
        tmp[i] = p1->data;
        p1 = p1->link;
    }

    sort(tmp, tmp + sizeof(tmp) / sizeof(int));

    for (int i = 0; i < 5; i++) {
        cout << tmp[i] << " ";
    }
}

int main() {
    list* p1 = (list*)malloc(sizeof(list));
    p1->data = 5;
    list* p2 = (list*)malloc(sizeof(list));
    p1->link = p2;
    p2->data = 3;
    list* p3 = (list*)malloc(sizeof(list));
    p2->link = p3;
    p3->data = 1;
    list* p4 = (list*)malloc(sizeof(list));
    p3->link = p4;
    p4->data = 2;
    list* p5 = (list*)malloc(sizeof(list));
    p4->link = p5;
    p5->data = 4;
    p5->link = NULL;
    
    sorting(p1);

	return 0;
}
