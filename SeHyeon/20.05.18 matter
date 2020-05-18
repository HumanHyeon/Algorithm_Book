#include <iostream>
using namespace std;

int inputSize;

void moveArray(int* input, int k) {
	int* tmp = new int[k];
	for (int i = 0; i <inputSize; i++) {
		if (i < k) //Can't use switch 
			tmp[i] = input[i];
		else
			input[i - k] = input[i];
	}
	for (int i = inputSize - k; i < inputSize; i++)
		input[i] = tmp[i - inputSize + k];
	delete[] tmp;
}

int main() {
	//int input[] = { 1, 2, 3, 4, 5 };
	int input[] = { 0, 1, 2, 3, 4 };
	int k;	cin >> k;
	
	inputSize = sizeof(input) / sizeof(input[0]);
	moveArray(input, k);

	for (int i = 0; i < inputSize; i++)
		cout << input[i] << " ";
}
