#include<iostream>
#include<array>
using namespace std;

array<int, 5>arr = { 1,2,4,0,3 };

int main() {
	for (int i = 0, j = 1; i < arr.size(); j++) {
		i = arr[i];
		if (i == 0 || i == arr[i]) {
			if (j < arr.size()) cout << "False\n";
			else cout << "True\n";
			break;
		}
	}
	getchar();
	return 0;
}

/*���� �迭 arr�� �ֽ��ϴ�. arr���� �� ������ ���� ���� ������ �ε����Դϴ�.
�̷��� ���� �̾����� ���ҵ��� �迭�� ������, arr[0]���� �����Ͽ� ��� ���Ҹ� �鸰 ���� �ٽ� arr[0]�� ������ �� �ִ��� ã���ÿ�.
��, �ð����⵵�� O(n), �������⵵�� O(1).

����)
Input: [1, 2, 4, 0, 3]
Output: True
// 1 -> 2 -> 4 -> 3 -> 0 -> 1

Input: [1, 4, 5, 0, 3, 2]
Output: False
// 1 -> 4 -> 3 -> 0 -> 1
// arr[2], arr[5]�� �鸮�� �ʾҽ��ϴ�.

Input: [1, 2, 2, 0]
Output: False
// 1 -> 2 -> 2 -> 2 -> ��
// arr[0]�� ���ƿ��� ���մϴ�.
*/