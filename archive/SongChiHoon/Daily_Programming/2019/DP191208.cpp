/*
정수로된 배열이 주어지면, 각 원소가 자신을 뺀 나머지 원소들의 곱셈이 되게하라.
단, 나누기 사용 금지, O(n) 시간복잡도

Given an integer array, make each element a product of all element values without itself.

예제)
input: [1, 2, 3, 4, 5]
output: [120, 60, 40, 30, 24]

해결방법
1. 입력 배열에서 자신이 제외된 배열 만들기.
2. 만들어진 배열의 값들 서로 곱하기.
3. 서로 곱한 값들의 결과값 출력
*/

#include <iostream>
#include <algorithm>
#define SIZE 5
using namespace std;

int temp[SIZE];
int ret = 1;

//배열값들 곱하는 함수
int multiply(int input[], int* count)
{
	ret *= input[*count];

	count++;

	if (*count < SIZE)
		return multiply(input, count);

	else
		return ret;
}

//자신이 제외된 배열 만드는 함수
int* Searchcreate(int input[], int count)
{
	int lap = 0;
	int array[SIZE];

	copy(input, input + SIZE, array);

	array[count] = 1;

	temp[count] = multiply(array, &count);

	lap++;

	if (lap == SIZE)
		return temp;
	else
	{
		count = 0;
		return Searchcreate(input, count);
	}

}

int main()
{
	int count = 0;
	int input[SIZE] = { 1, 2, 3, 4, 5 };

	cout << "Input : { ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << input[i] << " ";
	}
	cout << "}" << endl;

	cout << "Output : { ";
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << temp[i] << " ";
	}
	cout << "}";

	return 0;
}