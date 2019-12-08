#include <iostream>
using namespace std;
#define SIZE 5

int main()
{
	int arr[SIZE] = {1,2,3,4,5};
	int tmp1[SIZE], tmp2[SIZE];

	int accumulate = 1;

	for (int i = 0; i < SIZE; i++) {
		tmp1[i] = accumulate;
		accumulate *= arr[i];
	}

	accumulate = 1;

	for (int i = SIZE - 1; i >= 0; i--) {
		tmp2[i] = accumulate;
		accumulate *= arr[i];
	}
	cout << "output : ";
	for (int i = 0; i < SIZE; i++)
		cout << tmp1[i] * tmp2[i] << " ";
}
