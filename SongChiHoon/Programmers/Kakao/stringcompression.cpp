#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int length = s.length();
    if (length == 1) {
        answer = 1;
    }

    for (int i = 1; i <= length / 2; i++) {
        int count = 1;
        string base, comp, ret;
        base = s.substr(0, i);
        for (int j = i; j < length; j += i) {
            comp = s.substr(j, i);
            if (!(base.compare(comp))) {
                count++;
            }
            else {
                if (count == 1) {
                    ret += base;
                    base = comp;
                }
                else {
                    ret = ret + to_string(count) + base;
                    base = comp;
                    count = 1;
                }
            }
            if (i + j >= length) {
                if (count != 1) {
                    ret = ret + to_string(count) + base;
                    break;
                }
                else {
                    ret = ret + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > ret.length()) ? ret.length() : answer;
    }
    return answer;
}