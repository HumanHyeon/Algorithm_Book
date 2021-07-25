#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(string input) {
	for (auto elem : input) {
		int asc = elem;
		int sum = 0;
		while (asc > 0) {
			sum += asc % 10;
			asc /= 10;
		}
		for (int i = 0; i < sum; i++)
			cout << elem;
		cout << endl;
	}
}

int main() {
	string input;

	cin >> input;

	solution(input);
}
