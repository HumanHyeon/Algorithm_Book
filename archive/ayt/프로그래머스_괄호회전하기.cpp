#include <string>
#include <vector>
#include <stack>

using namespace std;

bool promising(string s) {
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
    
    if(promising(s)) ++answer;
    for(int i=0;i<s.size()-1;++i) {
        string tmp = "";
        string e = "";
        e = s[0];
        s.erase(0,1);
        tmp = s + e;
        
        if(promising(tmp)) ++answer;
        s = tmp;
    }
    
    return answer;
}
