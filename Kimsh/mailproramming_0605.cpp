#include<iostream>
#include<algorithm>
#include<array>
using namespace std;


/*
���� �迭�� �־����� , �迭 ���� ��� ������ �ִ� �����(GCD)�� ���Ͻÿ�.
�ٽð� ���⵵ ���� O(n)��
input: [3, 2, 1]
output: 1

input: [2, 4, 6, 8]
output: 2
*/
array <int, 3> arr = {3,2,1};
void prime_factorization(int a);//���μ�����
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