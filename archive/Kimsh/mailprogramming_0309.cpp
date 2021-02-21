#include<iostream>
#include<array>
#include<algorithm>
#include<functional>
using namespace std;
#define SIZE 5
int N = 1;
array <int,SIZE> arr = {2,4,-2,-3,8};

int main() {
	sort(arr.begin(), arr.end(),greater<int>());	

	for (int i = 0; i < SIZE; i++) {
		if (!(i+1 >= SIZE) && (arr[i] == arr[i + 1])) { 		
			arr[i + 1] = INT32_MIN;
		}
	}
	sort(arr.begin(), arr.end(), greater<int>());

	cout <<arr.at(N-1);

	getchar();
	return 0;
}

//���� �迭(int array)�� ���� N�� �־�����, N��°�� ū �迭 ���Ҹ� ã���ÿ�.
/*Input: [-1, 3, -1, 5, 4], 2
Output: 4

Input: [2, 4, -2, -3, 8], 1
Output: 8

Input: [-5, -3, 1], 3
Output: -5*/
