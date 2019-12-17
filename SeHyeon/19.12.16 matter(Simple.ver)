#include <iostream>
using namespace std;
#define SIZE 5

int calc(int arr[]) {
	int maxSum = arr[0];
	int currentSum = arr[0];
	for (int i = 1; i < SIZE; i++) {
		currentSum = currentSum + arr[i] > arr[i] ? currentSum + arr[i] : arr[i];
		maxSum = currentSum > maxSum ? currentSum : maxSum;
	}
	return maxSum;
}

int main()
{
	int arr[SIZE];		for (int i = 0; i < SIZE; i++)	cin >> arr[i];
	cout << calc(arr);
}
