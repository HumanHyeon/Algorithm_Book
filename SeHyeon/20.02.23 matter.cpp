#include <iostream>
using namespace std;

int main() {
	char matching[26];	memset(matching, NULL, sizeof(matching));
	bool answer = true;

	string input, compare;
	cin >> input >> compare;

	for (int i = 0; i < input.length(); i++) {
		if (matching[input[i] - 65]) {
			if (matching[input[i] - 65] == compare[i])	continue;
			else	answer = false;
		}
		else	matching[input[i] - 65] = compare[i];
	}

	if(answer)	cout << "True" << endl;
	else cout << "False" << endl;
}
