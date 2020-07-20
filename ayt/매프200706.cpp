#include <iostream>
using namespace std;
int count1(int inp) {
	int result = 0;
	while (1) {
		if (inp == 1) {
			++result;
			break;
		}

		if (inp % 2 == 1)
			++result;

		inp /= 2;
	}

	return result;
}
int main() {
	int input;
	cout << "input : ";
	cin >> input;
	cout << "output : " << count1(input) << endl;
	return 0;
}
