#include<iostream>
#include<array>
using namespace std;

array <int, 4> arr = { 0,3,10,60 };
int fnd = 0;
int output = -1;
void search(int n);
int main() {
	cout << "input : " << fnd << "\n";
	search(arr.size() / 2);
	cout << "output : " << output << "\n";
	return 0;
}
void search(int n) {
	cout << "arr[" << n << "] = " << arr[n] << " ";
	cout << "fnd = " << fnd << "\n";
	if (fnd == arr[n]) { cout << "찾음!\n"; output = n; return; }
	if (fnd < arr[n] && !(arr[n - 1] < fnd)) { cout << "n/2 search\n"; search(n / 2); return; }
	if (fnd > arr[n] && !(fnd < arr[n + 1])) { search(((n + 1) / 2) + 1); return; }
	return;
}
/*중복된 원소가 없는 정렬된 배열이 있습니다. 이 배열에서 원소의 값이 원소의 인덱스 값과 같다면 프린트 하시오. 시간복잡도 O(log n).

input: [-30, 1, 4, 60]
output: 1 // input[1] = 1



input: [0, 3, 10, 60]
output: 0 // input[0] = 0



input: [-40, -30, -20, 3]
output: 3 // input[3] = 3
*/