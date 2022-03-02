#include <iostream>
using namespace std;

void check(int inp[], int size) {
	int i = 0;
	int tmp = 0;

	while (1) {
		cout << inp[i] << " ";
		i = inp[i];
		tmp++;
		if (i == 0) {
			cout << inp[i];
			break;
		}
		else if (tmp > size)
			break;
	}
	cout << endl;

	if (tmp == size && i == 0)
		cout << "True";
	else
		cout << "False";
}

int main() {
	int input[] = { 3,2,0,4,1 };
	int size = sizeof(input) / sizeof(int);

	check(input, size);

	return 0;
}
