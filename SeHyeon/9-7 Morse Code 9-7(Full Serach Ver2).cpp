#include <iostream>
using namespace std;

int skip;

void generate(int n, int m, string s) {
	if (skip < 0)	return;
	if (n == 0 && m == 0) {
		if(skip == 0) cout << s << endl;
		skip--;
		return;
	}

	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

int main() {
	string s = "";
	int k;		cin >> k;		skip = k - 1;
	int n, m;	cin >> n >> m;
	generate(n, m, s);
}
