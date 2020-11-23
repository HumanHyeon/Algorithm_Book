#include <iostream>
using namespace std;

#define MAX_HEAP_SIZE 10
#define INDEX_ZERO -999

struct heap {
	int* S;
	int heapsize;
};

void siftdown(heap& H, int i) {
	int parent, largerchild;
	int siftkey;
	bool spotfound = false;

	siftkey = H.S[i];
	parent = i;
	while (2 * parent <= H.heapsize && !spotfound) {
		//find laergerchild
		if (2 * parent < H.heapsize && H.S[2 * parent] < H.S[2 * parent + 1]) largerchild = 2 * parent + 1;
		else largerchild = 2 * parent;
		
		if (siftkey < H.S[largerchild]) {
			H.S[parent] = H.S[largerchild];
			parent = largerchild;
		}
		else spotfound = true;
	}
	H.S[parent] = siftkey;
}

int root(heap& H) {
	int keyout;
	keyout = H.S[1];
	H.S[1] = H.S[H.heapsize];
	H.heapsize = H.heapsize - 1;
	siftdown(H, 1);
	return keyout;
}

void removekeys(int n, heap& H, int S[]) {
	int i;
	for (i = n; i >= 1; i--) S[i] = root(H);
}

void makeheap(int n, heap& H) {
	int i;
	for (i = n / 2; i >= 1; i--)
		siftdown(H, i);
}

void heapsort(int n, heap& H) {
	makeheap(n, H);
	removekeys(n, H, H.S);
}

void printHeap(heap& H) {
	cout << "heap: [ ";
	for (int i = 1; i <= MAX_HEAP_SIZE; i++) cout << H.S[i] << " ";
	cout << "]" << endl;
}

int main(void) {
	int a[MAX_HEAP_SIZE + 1] = { INDEX_ZERO, 1, 3, 4, 2, 7, 6, 5, 10, 8, 9 };
	heap h;
	h.S = a;
	h.heapsize = MAX_HEAP_SIZE;

	heapsort(h.heapsize, h);
	printHeap(h);
}
