#include <iostream>
using namespace std;

int search(int inp[], int k, int start, int end) {
	if (start >= end)
		return -1;

	int mid = (start + end) / 2;
	if (inp[mid] == k)
		return 1;
	else if (inp[mid] > k)
		return search(inp, k, start, mid - 1);
	else if (inp[mid] < k)
		return search(inp, k, mid + 1, end);
}

int findk(int inp[], int k, int start, int end) {
	int a, b;
	int mid = (start + end) / 2;

	if (inp[mid] < inp[mid - 1] && inp[mid] < inp[mid + 1]) {
		a = search(inp, k, 0, mid - 1);
		b = search(inp, k, mid, end);
	}
	else if (inp[mid] > inp[mid - 1] && inp[mid] > inp[mid + 1]) {
		a = search(inp, k, 0, mid);
		b = search(inp, k, mid + 1, end);
	}
	else {
		findk(inp, k, 0, mid + 1);
		findk(inp, k, mid, end);
	}

	if (a == -1 && b == -1)
		return -1;
	else
		return 1;
}


int main() {
	int input[] = { 7,8,9,1,2,3,4,5,6 };
	int k = 4;
	int size = sizeof(input) / sizeof(int);

	k %= size;
	cout << "output : " << findk(input, k, 0, size - 1);

	return 0;
}
