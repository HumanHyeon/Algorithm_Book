/*정수 배열과 정수 k가 주어지면 모든 원소를 k칸씩 앞으로 옮기시오.
Given an array and an integer K, shift all elements in the array K times.

input: [1, 2, 3, 4, 5], k = 2
output: [3, 4, 5, 1, 2]

input: [0, 1, 2, 3, 4], k = 1
output: [1, 2, 3, 4, 0]

시간복잡도와 공간복잡도를 최대한 최적화 하시오.*/
#include<iostream>
#include<array>
using namespace std;
int k;
array <int, 5> tmp;
array <int, 5> arr = { 0,1,2,3,4 };
int main() {
	cout << "정수 k 입력 : ";
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