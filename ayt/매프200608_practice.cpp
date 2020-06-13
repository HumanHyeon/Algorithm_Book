#include <iostream>
#define SIZE 100
using namespace std;

int tmp[SIZE] = { 0, };
int result;

void Gcd(int inp[],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= inp[i]; j++) {
			if (inp[i] % j == 0)
				++tmp[j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		if (tmp[i] == n)
			result = i;
	}
	cout << "ouput : " << result;
}

int main() {
	int input[] = { 2,4,6,8 };
	int size = sizeof(input) / sizeof(int);

	Gcd(input, size);

	return 0;
}
