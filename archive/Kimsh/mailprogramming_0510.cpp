#include<iostream>
#include<array>
using namespace std;

bool isin = false;
array <int, 5>arr= {1,2,3,7,10};	//�����
int fnd = 7;	//���� �����ϸ� ��
void search(int a, int b);

int main() {
	cout << "<-- search start -->\n";
	search(0, arr.size()-1);
	if (isin == false) cout << ". . .False\n";
	else cout << ". . .True\n";
	getchar();
	return 0;
}
void search(int a, int b) {
	if (fnd < arr[a] || fnd > arr[b]) return;
	else if(fnd == arr[a] || fnd == arr[b]) { isin = true; return; }

	int middle = (b - a) / 2;
	if (fnd < arr[middle]) { search(0, middle - 1); }
	else if (fnd > arr[middle]) { search(middle + 1, b); }

	return;
}
/*����(sort)�� ���� �迭�� ���� n�� �־�����, �迭�ȿ� n�� �ִ��� üũ�Ͻÿ�. �ð����⵵�� �ִ��� ����ȭ�Ͻÿ�.

����)

Input: [1, 2, 3, 7, 10], 7
Output: true

Input: [-5, -3, 0, 1], 0
Output: true

Input: [1, 4, 5, 6, 8, 9], 10
Output: false
*/