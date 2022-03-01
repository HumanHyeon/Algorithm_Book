#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<int> tmp;
    int cnt = 2;

    for (int i = 0; i < clothes.size(); ++i) {
        string kinds = clothes[i][1];
        bool tf = false;
        for (int j = i - 1; j >= 0; --j) {
            if (kinds == clothes[j][1]) {
                tf = true;
                break;
            }
        }
        if (tf == true) continue;
        for (int j = i + 1; j < clothes.size(); ++j) {
            if (kinds == clothes[j][1])
                ++cnt;
        }
        tmp.push_back(cnt);
        cnt = 2;
    }

    for (int i = 0; i < tmp.size(); ++i)
        if (tmp[i] != 0) answer *= tmp[i];
    --answer;

    return answer;
}
