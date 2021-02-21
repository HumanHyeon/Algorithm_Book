#include <string>
using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int size = 1; size <= s.size() / 2; size++) {
        int len = s.size();
        for (int i = 0; i < s.size(); i++) {
            string key = s.substr(i, size);
            int cnt = 0;
            for (int j = size; i + j < s.size(); j += size) {
                if (key == s.substr(i + j, size))   cnt++;
                else {
                    len -= size * cnt;
                    if (cnt) len += to_string(cnt + 1).size();
                    i += j - 1;
                    break;
                }
                if (i + j + size >= s.size()) {
                    len -= size * cnt;
                    len += to_string(cnt + 1).size();
                    i += j;
                }
            }
        }
        if (len < answer)    answer = len;
    }
    return answer;
}
