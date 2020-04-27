#include <iostream>
using namespace std;

string arrayCycle(int* input, int size) {
	int nextIndex = 0;
	for (int i = 0; i < size; i++) {
		nextIndex = input[nextIndex];
		if (nextIndex == 0 && i < size - 1)	return "False";
	}
	if (nextIndex == 0)	return "True";
	else return "False";
}

int main() {
	int input[] = { 1, 2, 4, 0, 3 };
	//int input[] = { 1, 4, 5, 0, 3, 2 };
	/*int input[] = { 1, 2, 2, 0 };*/

	cout << arrayCycle(input, sizeof(input) / sizeof(input[0])) << endl;
}
