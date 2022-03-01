#include <vector>
#include <string>
using namespace std;

string checkGH(string p) {
    if (p.empty()) return p;

    string u, v;

    int cnt = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++cnt;
        else --cnt;

        if (!cnt) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    cnt = 0;
    for (int i = 0; i < u.size(); ++i) {
        if (cnt == 0 && u[i] == ')') {
            ++cnt;
            continue;
        }
        if (u[i] == '(') ++cnt;
        else --cnt;
    }

    if (cnt == 0) {
        v = checkGH(v);
        return u + v;
    }
    else {
        u.erase(0, 1);
        u.erase(u.size() - 1, 1);
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        return "(" + checkGH(v) + ")" + u;
    }
}

string solution(string p){
    return checkGH(p);
}
