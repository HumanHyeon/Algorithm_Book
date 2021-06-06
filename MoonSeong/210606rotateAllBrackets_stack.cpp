#include <string>
#include <vector>

#include <stack>

using namespace std;

bool isRightBrackets(string s) {
    stack<char> brackets;
    
    for (int i = 0; i < s.length(); i++) {
        switch(s[i]) {
            case '(':
                brackets.push('r'); break;  //round
            case '[':
                brackets.push('s'); break;  //square
            case '{':
                brackets.push('c'); break;  //curly
            case ')':
                if (brackets.empty() || brackets.top() != 'r')
                    return false;
                brackets.pop();
                break;
            case ']':
                if (brackets.empty() || brackets.top() != 's')
                    return false;
                brackets.pop();
                break;
            case '}':
                if (brackets.empty() || brackets.top() != 'c')
                    return false;
                brackets.pop();
                break;
        }
    }
    if (brackets.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        s = s.substr(1, s.length()-1) + s.substr(0, 1);
        if (isRightBrackets(s))
            answer++;
    }
    
    return answer;
}
