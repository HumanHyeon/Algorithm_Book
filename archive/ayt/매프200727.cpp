#include <iostream>
#include <stack>
using namespace std;

stack<int> a;
stack<int> b;

void stackQ_push(int value) {
	a.push(value);
}

void stackQ_pop() {
	if (a.empty())
		cout << "no value" << endl;
	else {
		while (!a.empty()) {
			b.push(a.top());
			a.pop();
		}
		b.pop();
		while (!b.empty()) {
			a.push(b.top());
			b.pop();
		}
	}
}

int stackQ_front() {
	if (a.empty())
		return NULL;
	else {
		int result;

		while (!a.empty()) {
			b.push(a.top());
			a.pop();
		}

		result = b.top();

		while (!b.empty()) {
			a.push(b.top());
			b.pop();
		}

		return result;
	}
}

int stackQ_back() {
	if (a.empty())
		return NULL;
	else {
		return a.top();
	}
}

int main() {
	stackQ_push(1);
	stackQ_push(2);
	stackQ_push(3);
	stackQ_push(4);
	stackQ_push(5);

	cout << "front :	" << stackQ_front() << endl;
	cout << "back :	" << stackQ_back() << endl;

	stackQ_pop();

	cout << "front :	" << stackQ_front() << endl;
	cout << "back :	" << stackQ_back() << endl;

	return 0;
}
