#include <iostream>
using namespace std;

bool palindrome(char x[], int size) {
	int i = 0;
	while (true) {
		if ((x[i] == x[size - 1 - i])) return true;
		else return false;
	}
}

int main()
{
	char input[100] = { '\0', };
	int size = 0;

	cout << "Input: ";
	cin >> input;
	for (int i = 0; i < 100; i++) {
		if (input[i] != '\0') size++;
	}
	cout << size << endl;

	cout << "Oupit: ";
	if (palindrome(input, size)) cout << "true" << endl;
	else cout << "false" << endl;

	return 0;
}
