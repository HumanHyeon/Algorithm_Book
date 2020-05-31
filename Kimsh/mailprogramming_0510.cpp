#include<iostream>
#include<array>
using namespace std;

bool isin = false;
array <int, 5>arr= {1,2,3,7,10};	//여기랑
int fnd = 7;	//여기 수정하면 댐
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
/*정렬(sort)된 정수 배열과 정수 n이 주어지면, 배열안에 n이 있는지 체크하시오. 시간복잡도를 최대한 최적화하시오.

예제)

Input: [1, 2, 3, 7, 10], 7
Output: true

Input: [-5, -3, 0, 1], 0
Output: true

Input: [1, 4, 5, 6, 8, 9], 10
Output: false
*/