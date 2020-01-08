#include <iostream>
#include <math.h>
#define TEN 10
using namespace std;

bool palindrome(int* data, int start, int max) {
	if (start > (max / 2))	return true;
	if (data[start] != data[max - 1 - start])	return false;
	palindrome(data, ++start, max);
}

int main() {
	int input;	cin >> input;
	int count = 1, identify;
	int saveData[10];	//정수형은 약 21억까지 가질 수 있으므로 최대값은 10자리 수
	
	if (input < 0) {
		cout << "False" << endl;
		return 0;
	}

	identify = input;	//자리수 구하기
	while (true) {
		if (identify < TEN)	break;
		identify /= TEN;
		count++;
	}

	identify = (int)pow(TEN, count);	//배열에 숫자 분리
	for (int i = 0; i < count; i++, identify /= TEN) {
		saveData[i] = (input % identify) / (identify / TEN);
	}

	if (palindrome(saveData, 0, count)) cout << "True" << endl;
	else cout << "False" << endl;
}
