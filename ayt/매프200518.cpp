#include <iostream>
#include <algorithm>
using namespace std;

void shift(int inp[], int k, int size) {
	int tmp[100];

	if (k > size) k -= size;

	for (int i = 0; i < k; i++) {
		tmp[i] = inp[i];
		inp[i] = 123456789;
	}

	sort(inp, inp + size);

	int j = k;
	for (int i = 0; i < k; i++) {
		inp[size - j] = tmp[i];
		j--;
	}

	for (int i = 0; i < size; i++) {
		cout << inp[i] << " ";
	}
}

int main() {
	int input[] = { 1,2,3,4,5 };
	int k = 2;
	int size = sizeof(input) / sizeof(int);

	shift(input, k, size);

	return 0;
}
