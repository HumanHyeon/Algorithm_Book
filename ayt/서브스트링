#include <iostream>
#include <vector>
using namespace std;

int substring(char a[50]) {
	bool clear = false;
	vector<char> b;
	int result = 0;

	b.push_back(a[0]);
	for (int i = 0; i < strlen(a); i++) {
		if (i == 0 && a[0] != a[1]) {
			clear = false;
		}
		for (int j = 0; j < b.size(); j++) {
			if (b.at(j) == a[i])
				clear = true;
		}
		if (clear == true)
			b.clear();
		else if (clear == false && i != 0)
			b.push_back(a[i]);
		if (result < b.size())
			result = b.size();
		clear = false;
	}
	return result;
}
int main() {
	char input[50];
	int result;

	cin >> input;
	result = substring(input);
	cout << result;
	return 0;
}
