#include <iostream>
using namespace std;

//int input[] = { 1, 2, 3, 7, 10 };
//int input[] = { -5, -3, 0, 1};
int input[] = { 1, 4, 5, 6, 8, 9 };

bool binarySerch(int target, int start = 0, int end = sizeof(input) / sizeof(input[0]), int* arr = input) {
	int mid = (start + end) / 2;

	if (start > end)	return false;
	else {
		if (arr[mid] == target)	return true;
		else {
			if (arr[mid] < target)		binarySerch(target, mid + 1, end);
			else if (arr[mid] > target)	binarySerch(target, start, mid - 1);
		}
	}
}

int main() {
	binarySerch(9) == 1 ? cout << "True\n" : cout << "Flase\n";
}
