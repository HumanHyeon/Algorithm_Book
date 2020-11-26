#include <string>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int cnt = 1;
    string tmp = "";
    string result = "";

    for (int i = 1; i <= s.size(); ++i) {               // 비교 개수
        tmp = s.substr(0, i);
        
        for (int j = i; j < s.size(); j += i) {         // i만큼 비교
            if (tmp == s.substr(j, i))                  // 같으면 cnt + 1
                ++cnt;
            else {
                if (cnt == 1) {
                    result += tmp;
                    tmp = s.substr(j, i);
                }
                else {
                    result += to_string(cnt) + tmp;
                    tmp = s.substr(j, i);
                }
                cnt = 1;
            }

            if (i + j >= s.size()) {                    // 범위 밖을 참조 할 경우
                if (cnt == 1) {
                    result += s.substr(j);
                    break;
                }
                else {
                    result += to_string(cnt) + tmp;
                    break;
                }
            }
        }
        if (answer > result.length() && result.length() != 0) answer = result.length();
        cnt = 1;
        result = "";
    }

    return answer;
}
