#include <string>
#include <vector>

#include <iostream>

using namespace std;

string reverseBracket(string s) {
    string res = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(') res += ')';
        else res += '(';
    return res;
}

// -2: nullString -1:correct, 0:unbalanced, n:string[0..n] is least balanced
int checkBracket(string s) {
    int balance = 0;
    int balancedIndex = 0;
    bool isCorrect = true;
    bool flag = true;
    
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '(') balance++;
        if (s.at(i) == ')') balance--;
        if (balance < 0) isCorrect = false;
        if (flag && balance == 0) {
            flag == false;
            balancedIndex = i;
        }
    }
    
    if (s.length == 0) return -2;       //nullString
    if (balance != 0) return 0;         //unbalanced
    if (isCorrect) return -1;           //correct
    //none of all: balanced
    return return balancedIndex;
}

string solution(string p) {
    string answer = "";
    string u, v;
    
    if (p.length() == 0) return p;
    //하는중^^;;
    
    
    return answer;
}
