#include <iostream>
using namespace std;

bool binarySearch(int* arr, int start, int end, int find) {
	if (start > end)	return false;

	int mid = (start + end) / 2;
	if (arr[mid] == find)		return true;
	else if (arr[mid] < find)	binarySearch(arr, mid + 1, end, find);
	else if (arr[mid] > find)	binarySearch(arr, start, mid - 1, find);
}

int solution(int* arr, int start, int end, int index) {
	if (start > end)	return -1;

	int location = (start + end) / 2;
	
	if (arr[location] == index) {
		if (location == index)	return location;
		else return -1;
	}
	else if (arr[location] > index) {
		if (location > index)		solution(arr, start, location - 1, index);
		else if (location == index)	return -1;
		else if (location < index)	return -1;
	}
	else if (arr[location] < index) {
		if (location > index)		return -1;
		else if (location == index) return -1;
		else if (location < index)	solution(arr, location + 1, end, index);
	}
}

int main() {
	//int arr[] = { 0, 1, 2 ,3, 5, 6, 7, 8, 9 };
	//int arr[] = { -30, 1, 4, 60 };
	//int arr[] = { 0, 3, 10, 60 };
	int arr[] = { -40, -30, -20, 3 };

	cout << solution(arr, 0, sizeof(arr) / sizeof(arr[0]), 3) << endl;
}