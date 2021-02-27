#include <string>
#include <vector>

using namespace std;

string number = "0123456789";
string alphabat = "ABCDEF";

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt = 0;
    int order = 1;

    while (1) {
        string tmp = "";
        int num = cnt;
        if (num == 0) tmp += "0";
        while (num > 0) {
            if (num % n >= 10) tmp = alphabat[num % n - 10] + tmp;
            else tmp = number[num % n] + tmp;
            num /= n;
        }
        
        for (int i = 0; i < tmp.size(); ++i) {
            if (order > m) order = 1;
            if (order == p) answer += tmp[i];
            ++order;

            if (answer.size() == t) break;
        }

        if (answer.size() == t) break;
        ++cnt;
    }

    return answer;
}
