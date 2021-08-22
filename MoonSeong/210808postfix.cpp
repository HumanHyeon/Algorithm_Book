#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    string exp;
    string answer = "";
    cin >> exp;

    stack<char> s;
    
        for (int i = 0; i < exp.length(); i++) {
        switch(exp[i]) {
            case '+':
            case '-':
                if (s.empty() || s.top() == '(')
                    s.push(exp[i]);
                else {
                    while (true) {
                        if (s.empty() || s.top() == '(')
                            break;
                        answer.push_back(s.top());
                        s.pop();
                    }
                    s.push(exp[i]);
                }
                break;

            case '*':
            case '/':
                if (s.empty() || s.top() == '(')
                    s.push(exp[i]);
                else if (s.top() == '*' || s.top() == '/') {
                    answer.push_back(s.top());
                    s.pop();
                    s.push(exp[i]);
                }
                else
                    s.push(exp[i]);
                break;
            case '(':
                s.push(exp[i]);
                break;
            case ')':
                while (s.top() != '(') {
                    answer.push_back(s.top());
                    s.pop();
                }
                s.pop();
                break;
            default:
                answer.push_back(exp[i]);
                break;
        }
    }
    
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }

    cout << answer;

    return 0;
}
