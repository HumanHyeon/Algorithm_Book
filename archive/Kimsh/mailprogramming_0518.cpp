/*���� �迭�� ���� k�� �־����� ��� ���Ҹ� kĭ�� ������ �ű�ÿ�.
Given an array and an integer K, shift all elements in the array K times.

input: [1, 2, 3, 4, 5], k = 2
output: [3, 4, 5, 1, 2]

input: [0, 1, 2, 3, 4], k = 1
output: [1, 2, 3, 4, 0]

�ð����⵵�� �������⵵�� �ִ��� ����ȭ �Ͻÿ�.*/
#include<iostream>
#include<array>
using namespace std;
int k;
array <int, 5> tmp;
array <int, 5> arr = { 0,1,2,3,4 };
int main() {
	cout << "���� k �Է� : ";
	cin >> k;
	for (int i = 0; i < k; i++) {
		tmp[5 - i - 1] = arr[k - i - 1];
	}	
	for (int i = k; i < 5; i++) {
		tmp[i-k] = arr[i];
	}

	for (int i = 0; i < 5; i++) {
		cout << tmp[i] << " ";
	}
	getchar();
	getchar();
	return 0;
}