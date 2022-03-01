#include <iostream>
using namespace std;

bool powerof4(int inp) {
	int n = 4;

	if (n > inp)
		return false;

	while (n <= inp) {
		if (n == inp)
			return true;
		n *= 4;
	}

	return false;
}

int main() {
	int input = 256;

	if (powerof4(input) == true)
		cout << "true";
	else
		cout << "false";

	return 0;
}
