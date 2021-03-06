#include <iostream>
using namespace std;

int input[] = { 1, 3, 6, 8, 9, 11, 13};

int binarySearch(int* division, int key, int start, int end) {
	int mid = (start + end) / 2;

	if (division[mid] == key)		return mid;
	else if (start >= end)			return -1;
	
	if (division[mid] < key)			binarySearch(division, key, mid + 1, end);
	else if (division[mid] > key)		binarySearch(division, key, start, mid - 1);
}

int findKey(int* ip, int k, int size = sizeof(input)/sizeof(input[0])) {
	int range = k % size;
	int result1, result2;

	result1 = binarySearch(ip, k, 0, size - range - 1);
	result2 = binarySearch(ip, k, size - range, size - 1);

	if (result1 == -1 && result2 == -1)	return -1;
	if (result1 > result2)	return result1;
	else			return result2;
}

void moveArray(int *ip, int k, int size = sizeof(input) / sizeof(input[0])) {
	k %= size;
	int* tmp = new int[k];

	for (int i = 0; i < size; i++) 
		if (i < k)	tmp[i] = ip[i];
		else		ip[i - k] = ip[i];
	for (int i = 0; i < k; i++)		ip[(size - k) + i] = tmp[i];

	delete tmp;
}

int main() {
	int k;	cin >> k;
	int answer;

	moveArray(input, k);
	answer = findKey(input, k);

	for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
		cout << input[i] << " ";
	cout << "\n" << answer << endl;
}
