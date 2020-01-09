#include <iostream>
#include <vector>
#include <string>
using namespace std;

void parentheses(int num, int open, int close, string s, vector<string>& list) {
	if (close == num) {			//completed
		list.push_back(s);
		return;
	}

	if (open < num)				//uncompleted
		parentheses(num, open + 1, close, s + "(", list);
	if (close < open)
		parentheses(num, open, close + 1, s + ")", list);
}

int main() {
	int num;	cin >> num;
	vector<string> list;

	parentheses(num, 0, 0, "", list);

	for (vector<string>::iterator iter = list.begin(); iter != list.end(); iter++)
		cout << *iter << endl;
	cout << list.size() << endl;
}
