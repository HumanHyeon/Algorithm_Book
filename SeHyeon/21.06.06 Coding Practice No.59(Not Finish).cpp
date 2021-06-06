https://programmers.co.kr/learn/courses/30/lessons/76502

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isCorrectBracket(string s) {
    const int SQUARE = 0;   //[]
    const int CURLY = 1;    //{}
    const int BRACES = 2;   //()
    int status[3] = { 0, 0, 0 };
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[') {
            status[SQUARE]++;        
        }
        else if (s[i] == '{') {
            status[CURLY]++;
        }
        else if (s[i] == '(') {
            status[BRACES]++;
        }
        else if (s[i] == ']') {
            if (status[SQUARE] == 0)
                return (false);
            status[SQUARE]--;
        }
        else if (s[i] == '}') {
            if (status[CURLY] == 0)
                return (false);
            status[CURLY]--;
        }
        else if (s[i] == ')') {
            if (status[BRACES] == 0)
                return (false);
            status[BRACES]--;
        }
    }
    if (status[SQUARE] || status[CURLY] || status[BRACES])
        return (false);
    return (true);
}

string cycleString(string s, int n) {
    string tmp = "";

    if (n == 0)
        return (s);
    for (int i = n; i < s.size(); i++)
        tmp += s[i];
    for (int i = 0; i < n; i++)
        tmp += s[i];
    return (tmp);
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) {
        string fetch;

        fetch = cycleString(s, i);
        if (isCorrectBracket(fetch))
            answer++;
    }
    return answer;
}

int main() {
    string s = "{{{{{";

    cout << solution(s) << endl;
}
