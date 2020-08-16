#include<iostream>
#include<array>
using namespace std;
/*중복된 원소가 없는 정렬된 배열이 있습니다. 이 배열에서 원소의 값이 원소의 인덱스 값과 같다면 프린트 하시오. 시간복잡도 O(log n).

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