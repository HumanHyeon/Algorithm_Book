#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve(string N) {
	vector<char> v1; // 알파벳
	vector<char> v2; // 괄호
	vector<char> v3; // 연산
	bool ck = false;

	for (auto elem : N) {
		if (elem >= 'A' && elem <= 'Z') {
			v1.push_back(elem);
			if (ck && v2.empty()) {
				int s = v3.size();
				for (int i = 0; i < s; i++) {
					v1.push_back(v3.back());
					v3.pop_back();
				}
				ck = false;
			}
		}
		else {
			if (elem == '(') {
				v2.push_back(elem);
			}
			else if (elem == ')') {
				v2.pop_back();
				v1.push_back(v3.back());
				v3.pop_back();
			}
			else {
				if (elem == '*' || elem == '/') {
					v3.push_back(elem);
					ck = true;
				}
				else v3.push_back(elem);
			}
		}
	}

	int s = v3.size();
	for (int i = 0; i < s; i++) {
		v1.push_back(v3.back());
		v3.pop_back();
	}

	for (auto elem : v1) cout << elem;
}

int main() {
	string N;
	cin >> N;

	solve(N);

	return 0;
}
