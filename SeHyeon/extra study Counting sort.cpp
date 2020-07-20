#include <iostream>
using namespace std;

int main() {
	//Preparation process
	int original[] = { 3, 4, 0, 1, 2, 4, 2, 4 };
	int size = sizeof(original) / sizeof(original[0]);
	int largeNum = -1;
	 
	for (int i = 0; i < size; i++) 
		if (largeNum < original[i])	largeNum = original[i];
	int* intermediate = new int[largeNum + 1];
	int* result = new int[size];

	//memset(intermediate, 0, largeNum + 1);		//Critical error
	for (int i = 0; i < largeNum + 1; i++) 
		intermediate[i] = 0;

	//Sorting process
	for (int i = 0; i < size; i++) 				//count each Num
		intermediate[original[i]]++;
	
	for (int i = 0; i < largeNum; i++)			//calc accumulate
		intermediate[i + 1] += intermediate[i];
	
	for (int i = 0; i < size; i++) {			//input result
		result[intermediate[original[i]] - 1] = original[i];
		intermediate[original[i]]--;
	}

	//Print & Finishing process
	for (int i = 0; i < size; i++)
		cout << result[i] << " ";
	putchar('\n');

	delete[] intermediate;
	delete[] result;
}
