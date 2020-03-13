#include <iostream>
using namespace std;

void swap(int* arr, int x, int y) {
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

int partition(int* arr, int start, int end) {
	int pivot_spot = start;
	for (int i = start; i < end; i++) {
		if (arr[i] > arr[end]) {
			swap(arr, i, pivot_spot);
			pivot_spot++;
		}
	}
	swap(arr, pivot_spot, end);
	return pivot_spot;
}

int quickselect(int* arr, int key) {
	return quickselect(arr, 0, (sizeof(arr) / sizeof(*arr)) - 1, key - 1);
}

int quickselect(int* arr, int start, int end, int key) {
	if (start <= end) {
		int pivot = partition(arr, start, end);
		if (pivot == key)	return arr[key];
		if (pivot > key)	return quickselect(arr, start, pivot - 1, key);
		return quickselect(arr, pivot + 1, end, key);
	}
	return Integer.MIN_VALUE;	//???
}
