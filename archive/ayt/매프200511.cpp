#include <iostream>
using namespace std;

int s;

void check(int inp[], int n) {
	for (int i = 0; i < s; i++) {
		if (n == inp[i]) {
			cout << "true";
			return;
		}
	}
	cout << "false";
}

int main() {
	int input[] = { 1,2,3,7,10 };
	int n = 7;
	s = sizeof(input) / sizeof(int);

	check(input, n);

	return 0;
}
