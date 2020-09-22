// // 단방향 연결 리스트(singly linked list)가 주어지면 총 합이 0으로 되는 연결된 노드들을 뺀 뒤 남은 노드의 값을 프린트 하시오.

// Given a linked list, remove consecutive nodes that sum to zero. Print the values of leftover nodes.

// input: 3 -> (-5) -> 5 -> 1 -> 2 -> 3

// output: 3 -> 1 -> 2 -> 3

// input: 1 -> 2 -> 3 -> 4 -> (-10) -> 5

// output: 5

// input: 10 -> (-3) -> (-4) -> (-3) -> 1

// output: 1
#include <iostream>

using namespace std;

struct NODE {
	int DATA;
	NODE *next;
};

NODE *nodelist;	// kind of iterator, contains current node address.

void add(int key) {
	NODE * new_node = new NODE;
	new_node->DATA = key;
	new_node->next = NULL;

	if(nodelist == NULL) {
		nodelist = new_node;
	}
	else {
		new_node->next = nodelist;
		nodelist = new_node;
	}
}

void printnodelist(NODE *list) {
	NODE *current = list;
	while (current != NULL) {
		cout << current->DATA << " -> ";
		current = current ->next;
	}

	cout << "NULL\n";
}

int main() {
	int input[6] = {3, -5, 5, 1, 2, 4};
	nodelist

}