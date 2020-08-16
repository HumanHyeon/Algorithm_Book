#include<iostream>
#include<array>
using namespace std;
/*�ߺ��� ���Ұ� ���� ���ĵ� �迭�� �ֽ��ϴ�. �� �迭���� ������ ���� ������ �ε��� ���� ���ٸ� ����Ʈ �Ͻÿ�. �ð����⵵ O(log n).

input: [-30, 1, 4, 60]

output: 1 // input[1] = 1



input: [0, 3, 10, 60]

output: 0 // input[0] = 0



input: [-40, -30, -20, 3]

output: 3 // input[3] = 3
*/
array <int, 4> arr = { -30,1,4,60 };
int fnd = 1;
int search(int n);
int main() {
	cout << "input : " << fnd << "\n";
	search(arr.size()/2);
	getchar();
	return 0;
}
int search(int n) {
	if (fnd == arr[n]) return n;

	if (fnd < arr[n]) {
		search((n - 1) / 2);
		return;
	}
	else if (fnd > arr[n]) {
		search(n + 1 / 2);
		return;
	}

}