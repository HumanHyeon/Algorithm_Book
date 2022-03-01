#include <iostream>
using namespace std;

int inp[] = { 3,1,5,6 };

void quick(int x, int y) {
	if (x >= y) return;
	int p = inp[(x + y) / 2];
	int left = x;
	int right = y;

	while (left <= right) {
		while (inp[left] < p) left++;
		while (inp[right] > p) right--;
		if (left <= right) {
			swap(inp[left], inp[right]);
			left++, right--;
		}
	}
	quick(x, right);
	quick(left, y);
}

void display(int inp[]) {
	for (int i = 0; i < 4; i++) {
		cout << inp[i] << " ";
	}
}

int main() {
	quick(0, 4);
	display(inp);

	return 0;
}
