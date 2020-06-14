#include <iostream>
using namespace std;

int input[] = { 2,4,6,8 };

int tmpGcd(int a, int b) {
	if (b == NULL)
		return a;
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
		int tmp = b;
		b %= a;
		a = tmp;
	}

	return a;
}

int findGcd() {
	int nowgcd = NULL;

	for (int i : input) {
		nowgcd = tmpGcd(i, nowgcd);
	}

	return nowgcd;
}

int main() {
	cout << "output : " << findGcd();

	return 0;
}
