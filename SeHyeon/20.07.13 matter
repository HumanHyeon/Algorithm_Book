#include <iostream>
#include <queue>
#define ASC 1
#define DESC 0
using namespace std;

void radix_sort(int* arr, int size, int flag) {
	queue<int> bucket[10];
	int digit = 0, div = 1;

	//Calc digit part
	int largeNum = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > largeNum) largeNum = arr[i];
	for (int i = largeNum; i > 0; i /= 10) digit++;

	//Sorting process
	for (int i = 0; i < digit; i++, div *= 10) {	//Cycle count
		for (int j = 0; j < 10; j++) {				//Decimal bucket
			for (int k = 0; k < size; k++) {		//Array Cycle
				if ((arr[k] / div) % 10 == j)
					bucket[j].push(arr[k]);
			}
		}
		int index = 0;

		if (flag) {
			for (int j = 0; j < 10; j++) {
				while (!bucket[j].empty()) {
					arr[index] = bucket[j].front();
					bucket[j].pop();
					index++;
				}
			}
		}
		else {
			for (int j = 9; j >= 0; j--) {
				while (!bucket[j].empty()) {
					arr[index] = bucket[j].front();
					bucket[j].pop();
					index++;
				}
			}
		}
	}
}

void solution(int* arr, int size) {
	int* negative = new int[size];
	int* positive = arr;

	int negative_count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			negative[negative_count++] = -arr[i];
			arr[i] = 0;
		}
	}

	radix_sort(positive, size, ASC);
	radix_sort(negative, negative_count, DESC);
	
	for (int i = 0; i < negative_count; i++)	arr[i] = -negative[i];
	for (int i = negative_count; i < size; i++)	arr[i] = positive[i];

	delete[] negative;
}

int main() {
	int arr[] = { 100000, -1, -3, -5, 0, -2, 11, 1, 1, 83, 202, 119, 55, 4, 19, 28, -1, 1004, 2005, 3, 7979, 10000 };
	int size = sizeof(arr) / sizeof(arr[0]);

	solution(arr, size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	putchar('\n');
}
