#include <iostream>
using namespace std;

/*�־��� ������ 2�������� ��Ÿ�������� 1�� ������ �����Ͻÿ�.

�ð� ���⵵: O(log n)

input: 6 // 110
output: 2

input: 13 // 1101
output: 3
*/
int main() {
	int cnt = 0;
	int a = 0;
	cout << "input : ";
	cin >> a;

	while (a>0) {
		a % 2 == 1 ? cnt += 1:cnt+=0;
		a = a / 2;
	}
	
	cout << "output : " << cnt<<"\n";

	return 0;
}