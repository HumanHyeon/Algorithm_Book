#include <iostream>
using namespace std;

string e, digits;
int n, m;

string price;
//bool taken[15];	전역변수로 놓으면 정적 바인딩이라 모든 재귀 호출 함수 쪽에서 동일한 배열을 사용하지만
//					매개변수로 배열을 넘겨 줄 시 동적 바인딩이므로 재귀 호출 마다 새로운 taken 배열이 생성 되기 때문에 매개변수로 넘겨줌

void generate(string price, bool taken[15]) {
	if (price.size() == n) {
		if (price < e)
			cout << price << endl;
		return;
	}
	for(int i = 0; i < n; i++)
		if (!taken[i] && (i == 0 || digits[i - 1] != digits[i] || taken[i - 1])) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
}
