#include <iostream>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
	int C;
	string input;
	string::iterator a;
	string result[50];
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> input;
		a = input.begin();
		result[i] = reverse(a);
	}
	for (int i = 0; i < C; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
