#include <string>
#include <vector>
#include <cmath>

using namespace std;

string resultValue(string a, string b, string c) {
    if (b == "*")
        return to_string(stol(a) * stol(c));
    else if (b == "+")
        return to_string(stol(a) + stol(c));
    else if (b == "-")
        return to_string(stol(a) - stol(c));
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> exp;
    vector<string> order = { "*+-","*-+","+*-","+-*","-*+","-+*" };

    // expression을 숫자와 기호로 나눔
    string tmp = "";
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] < '0' || expression[i] > '9') {
            exp.push_back(tmp);
            tmp = "";
            tmp += expression[i];
            exp.push_back(tmp);
            tmp = "";
        }
        else if (i == expression.size() - 1) {
            tmp += expression[i];
            exp.push_back(tmp);
        }
        else tmp += expression[i];
    }

    // 계산
    tmp = "";
    for (int i = 0; i < order.size(); ++i) {
        vector<string> tmpExp = exp;
        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < tmpExp.size(); ++j) {
                tmp += order[i][k];
                if (tmpExp[j] == tmp) {
                    tmpExp[j] = resultValue(tmpExp[j - 1], tmpExp[j], tmpExp[j + 1]);
                    tmpExp.erase(tmpExp.begin() + j - 1);
                    --j;
                    tmpExp.erase(tmpExp.begin() + j + 1);
                }
                tmp = "";
            }
        }
        answer = answer < abs(stol(tmpExp[0])) ? abs(stol(tmpExp[0])) : answer;
    }

    return answer;
}
