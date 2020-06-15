#include<iostream>
#include<algorithm>
#include<array>
using namespace std;


/*
정수 배열이 주어지면 , 배열 안의 모든 정수의 최대 공약수(GCD)를 구하시오.
☆시간 복잡도 제한 O(n)☆
input: [3, 2, 1]
output: 1

input: [2, 4, 6, 8]
output: 2
*/
array <int, 3> arr = {3,2,1};
void prime_factorization(int a);//소인수분해
int main() {
	int min = INT16_MAX;
	for (int i = 0; i < 3; i++) {
		if (arr[min] > arr[i]) min = i ;
	}
	prime_factorization(min);
	return 0;
}
void prime_factorization(int a) {
	int find = true;
	for (int i = 0; i < 3; i++) {
		if (arr[i] % a != 0) {
			find = false;
		}
	}	 

}