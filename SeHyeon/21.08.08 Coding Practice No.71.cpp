https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' ||
			c == '/' || c == '(' || c == ')');
}

void solution(string expression) {
	stack<char> postfix;
	string output = "";

	for (auto fetch : expression) {
		if (!isOperator(fetch)) 
			output += fetch;
		else {	//fetch가 연산자인 경우
			if (postfix.empty() || fetch == '(') {	//비어있는 경우 바로 넣음, 좌측 괄호도 바로  넣음
				postfix.push(fetch);
				continue;
			}
			//비어있지 않은 경우
			else if (fetch == ')') {
				while (postfix.top() != '(') {
					output += postfix.top();
					postfix.pop();
				}
				postfix.pop();
				continue;
			}
			else if (fetch == '+' || fetch == '-') {
				if (postfix.top() == '+' || postfix.top() == '-'){
					output += postfix.top();
					postfix.pop();
				}
				postfix.push(fetch);
				continue;
			}
			else if (fetch == '*' || fetch == '/') {
				while (postfix.top() == '*' || postfix.top() == '/') {
					output += postfix.top();
					postfix.pop();
				}
				postfix.push(fetch);
				continue;
			}
		}
	}
	while (!postfix.empty()){
		output += postfix.top();
		postfix.pop();
	}
	cout << output;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;

	cin >> input;
	solution(input);
}
//
//(A+B)*C-D
//answer : AB + C * D -
