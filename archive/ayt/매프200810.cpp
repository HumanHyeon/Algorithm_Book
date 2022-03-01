#include <iostream>
using namespace std;

int findEqual(int *inp, int n) {
	int start = 0;
	int end = n - 1;
	int mid, key;

	while (end - start >= 0) {
		mid = (start + end) / 2;
		key = mid;

		if (inp[mid] == key)
			return key;
		else if (inp[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
}

int main() {
	int input[] = { -30,1,4,60 };
	int size = sizeof(input) / sizeof(int);

	cout << "output : " << findEqual(input, size);

	return 0;
}
