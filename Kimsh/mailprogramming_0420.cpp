#include<iostream>
using namespace std;
/*2차 정수 배열(2D int array)가 주어지면, 소용돌이 모양으로 원소들을 프린트하시오. 예제를 보시오.
예제)

﻿input:
[[1, 2, 3],
[8, 9, 4],
[7, 6, 5]]
Output:
1, 2, 3, 4, 5, 6, 7, 8, 9*/
#define SIZE 3;
int arr[3][3] = {
	{1,2,3},
	{8,9,4},
	{7,6,5},
};
void Snail(int a, int b);
int main() {
	int index = SIZE;
	Snail(0,index);
	getchar();
	return 0;
}
void Snail(int a, int b) {
	if (a == (b-1)) { cout << arr[a][a]; return; }
	for (int i = a; i < b; i++)
	{
		if (i == a)
			for (int j = a; j < b; j++) cout << arr[i][j] << ", ";
		else if (i == b - 1) for (int j = b - 1; j > a; j--) cout << arr[i][j] << ", ";
		else cout << arr[i][b - 1] << ", ";
	}
	if (((b - 1) - a) != 1) {
		for (int i = b - 1; i > a; i--) cout << arr[i][a] << ", ";
	}
	else if ((b - 1) - a == 1) { cout << arr[a+1][a];  return; }
	Snail(a+1, b-1);
	return;
}
