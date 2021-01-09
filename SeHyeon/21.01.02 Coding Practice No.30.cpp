#include <string>
#define BRACKET(C) ((C) == '(' ? left++ : right++)
using namespace std;

bool properBracket(string u) {
    if (u[0] == ')') return false;
    int left = 1, right = 0;
    for (int i = 1; i < u.size(); i++) {
        BRACKET(u[i]);
        if (left < right) return false;
    }
    return true;
}

string solution(string w) {
    if (w == "") return ""; //step 1

    int left = 0, right = 0, i; //step 2
    for (i = 0; i < w.size(); i++) {
        BRACKET(w[i]);
        if (left == right) break;
    }
    string u = w.substr(0, i + 1);
    string v = w.substr(i + 1, w.size());
    
    if (properBracket(u)) { //step 3
        return u + solution(v);
    }
    else { //step 4
        string result;
        result = "(" + solution(v) + ")";   //4-1, 4-2, 4-3
        for (int j = 1; j < u.size() - 1; j++) {
            if (u[j] == '(') result += ")";
            else result += "(";
        }
        return result;
    }
}
