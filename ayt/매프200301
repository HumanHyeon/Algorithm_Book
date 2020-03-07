#include <iostream>
using namespace std;

int main()
{
	int input[5] = { 1,2,3,4,5 };
	int input1[] = {
		1,
		input[0],
		input[0] * input[1],
		input[0] * input[1] * input[2],
		input[0] * input[1] * input[2] * input[3]
	};
	int input2[] = {
		input[1] * input[2] * input[3] * input[4],
		input[2] * input[3] * input[4],
		input[3] * input[4],
		input[4],
		1
	};
	int Output[5];
	for (int i = 0; i < 5; i++)
		Output[i] = input1[i] * input2[i];

	cout << "Input: ";
	for (int i = 0; i < 5; i++)
		cout << input[i] << " ";
	cout << endl;

	cout << "Output: ";
	for (int i = 0; i < 5; i++)
		cout << Output[i] << " ";

	return 0;
}
