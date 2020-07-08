#include <iostream>
using namespace std;

int input[] = { 1, 2, 3, 8 };
int arr_size = sizeof(input) / sizeof(input[0]);
int identify = 0;

bool ok = true;

void id(int* input2, int key) {
	int tmp;
	for (int i = 0; i < arr_size; i++) {
		tmp = input[i];
		key -= tmp;
		input[i] = 0;
		id(input, key);
		input[i] = tmp;
	}
	identify = key;
}


int solution(int *input) {
	int i;
	for (i = 1; identify != 0; i++) id(input, i);
	return i;
}

int main() {
	cout << solution(input) << endl;
}
