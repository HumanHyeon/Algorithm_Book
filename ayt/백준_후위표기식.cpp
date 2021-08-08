#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(string N) {
	vector<char> v;
    string result;

    for (auto elem : N) {
        if ('A' <= elem && elem <= 'Z')
            result += elem;
        else {
            switch (elem) {
            case '(':
                v.push_back(elem);
                break;
            case '*':
            case '/':
                while (!v.empty() && (v.back() == '*' || v.back() == '/')) {
                    result += v.back();
                    v.pop_back();
                }
                v.push_back(elem);
                break;
            case '+':
            case '-':
                while (!v.empty() && v.back() != '(') {
                    result += v.back();
                    v.pop_back();
                }
                v.push_back(elem);
                break;
            case ')':
                while (!v.empty() && v.back() != '(') {
                    result += v.back();
                    v.pop_back();
                }
                v.pop_back();
                break;
            }
        }
    }

    while (!v.empty()) {
        result += v.back();
        v.pop_back();
    }

    cout << result;
}

int main() {
	string N;
	cin >> N;

	solve(N);

	return 0;
}
