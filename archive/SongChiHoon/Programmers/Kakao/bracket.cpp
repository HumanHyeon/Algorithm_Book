#include <string> 
#include <vector> 
#include <stack> 
using namespace std; 

// 올바른 괄호 문자열인지 판단하는 함수 

bool is_right(string& str) {
    if (!str.size()) {
        return true;
    }

    stack<char> stc; 
    
    if (str[0] == ')') {
        return false;
    }

    else {
        stc.push(str[0]);
    }

    for (int i = 1; str[i]; i++) { 
        if (str[i] == ')') { 
            if (stc.empty()) {
                return false;
            }
            stc.pop(); 
        } 
        else if (str[i] == '(') {
            stc.push('('); 
        } 
    }
    if (stc.empty()) {
        return true;
    } 
    else {
        return false; 
    } 
}

// u가 올바른 문자열이 아닌 경우 앞뒤를 자르고 괄호를 바꾸는 함수 
    
string make_str(string changebracket) { 
    if (changebracket.size() <= 2) {
        return "";
    } 
    string ret = ""; 
    for (int i = 1; i < changebracket.size() - 1; i++) { 
        ret += (changebracket[i] == '(' ? ')' : '('); 
    } 
    return ret; 
}

// 문자열에 대해 반복적으로 해당 과정을 수행하는 함수 

string recur(string input) { 
    if (input.size()) { 
        int cnt = (input[0] == '(' ? 1 : -1); 
        int off = 1; 
        while(cnt) { 
            cnt += (input[off++] == '(' ? 1 : -1); 
        } 
        string before_middle = input.substr(0, off); // 문자 처음부터 off - 1까지 
        string v = input.substr(off); // off부터 문자 끝까지 
        
        // u가 올바른 문자열인 경우 
        if (is_right(before_middle)) return before_middle + recur(v); 
        
        // u가 올바른 문자열이 아닌 경우 
        else 
            return '(' + recur(v) + ')' + make_str(before_middle); 
        } 
        return "";
    } 
    
string solution(string input) {
    return recur(input);
}