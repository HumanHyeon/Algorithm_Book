#include <iostream>
#include <queue>
using namespace std;

int main() {
	int arr[] = { 100000, 11, 1, 1, 83, 202, 119, 55, 4, 19, 28, 1004, 2005, 3, 7979, 10000 };
	int size = sizeof(arr) / sizeof(arr[0]);

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
		for (int j = 0; j < 10; j++) {
			while (!bucket[j].empty()) {
				arr[index] = bucket[j].front();
				bucket[j].pop();
				index++;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	putchar('\n');
}
