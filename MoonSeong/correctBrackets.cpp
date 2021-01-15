#include <string>
#include <vector>
using namespace std;

string reverseBracket(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(') res += ')';
        else res += '(';
    return res;
}

// return Index where string[0..n] is the least balanced
int checkBracket(string s) {
    int balance = 0;
    int balancedIndex = 0;
    bool flag = true;

    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '(') balance++;
        if (s.at(i) == ')') balance--;
        if (flag == true && balance == 0) {
            flag = false;
            balancedIndex = i;
        }
    }

    return balancedIndex;
}

bool isCorrectBracket(string s) {
    int balance = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '(') balance++;
        if (s.at(i) == ')') balance--;
        if (balance < 0) return false;
    }
    return true;
}

string solution(string p) {
    string u, v;
    string answer;
    int check;

    if (p.length() == 0) return p;

    check = checkBracket(p);
    u = p.substr(0, check + 1);
    v = p.substr(check + 1, p.length() - check - 1);

    if (isCorrectBracket(u))
        answer = u + solution(v);
    else
        answer = '(' + solution(v) + ')' + reverseBracket(u.substr(1, u.length() - 2));

    return answer;
}
