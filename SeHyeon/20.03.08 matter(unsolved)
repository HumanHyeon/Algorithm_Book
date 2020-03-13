#include <iostream>
#define SIZE 9
using namespace std;

int quickselection(int* arr, int key, int start = 0, int end = SIZE) {
	int pivot = arr[start];
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (arr[left] > pivot)	left++;		//find smaller than pivot
		while (arr[right] < pivot)	right--;	//find bigger than pivot
		if (left <= right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		else {
			int tmp = arr[right];
			arr[right] = pivot;
			arr[start] = tmp;
		}
	}

	if ((key - 1) == right)		return pivot;
	else if((key - 1) > right)  quickselection(arr, key, start, right - 1);
	else if((key - 1) < right)	quickselection(arr, key, right + 1, end);
}

int main()
{
	int arr[] = { 4, 1, 2, 3, 9, 7, 8, 6, 10, 5 };
	
	cout << quickselection(arr, 2) << endl;
}
