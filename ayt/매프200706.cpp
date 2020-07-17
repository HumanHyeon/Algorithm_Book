#include <iostream>
#include <cmath>
using namespace std;

void smallInt(int inp[], int n) {
	int tmp, sum = 0;
	bool check = false;

	for (int i = 0; i < n; ++i) {
		if (inp[i] != pow(2, i)) {
			check = true;
			break;
		}		
	}

	if (check == false) {
		for (int i = 0; i < n; ++i) {
			sum += inp[i];
		}
		cout << "output : " << ++sum;
	}

	if (inp[0] != 1)
		cout << "output : 1";
	else {
		for (int i = 1; i <= n; ++i) {
			if (inp[i - 1] != i) {
				tmp = i;
				break;
			}
		}

		for (int i = 1; i < tmp; i++) {
			sum += i;
		}
		cout << "output : " << ++sum;
	}
}

int main() {
	int input[] = { 1,2,3,8 };
	int size = sizeof(input) / sizeof(int);

	smallInt(input, size);

	return 0;
}
