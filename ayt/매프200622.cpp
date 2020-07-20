#include <iostream>
using namespace std;

int smallInt(int inp[], int n) {
	int ck[100] = { 0, };

	if (inp[0] != 1)
		return 1;
	if (inp[1] != 2)
		return 2;

	for (int i = 0; i < n; ++i) {
		ck[inp[i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ck[inp[i] + inp[j]] = 1;
		}
	}
	for (int i = 1; i < 100; ++i) {
		if (ck[i] == 0) {
			return i;
			break;
		}
	}
}

int main() {
	int input[] = { 1,2,3,6,10 };
	int size = sizeof(input) / sizeof(int);

	cout << "output : " << smallInt(input, size);

	return 0;
}
