#include <iostream>
#include <stack>
using namespace std;

int solution(int input) {
	stack<int> binary;
	int result = 0;

	while (true) {
		if (input == 1) {
			binary.push(1);
			break;
		}
		binary.push(input % 2);
		input /= 2;
	}

	while (!binary.empty()) {
		if (binary.top() == 1)	++result;
		binary.pop();
	}
	return result;
}

int main() {
	int input;	cin >> input;

	cout << solution(input) << endl;
}
