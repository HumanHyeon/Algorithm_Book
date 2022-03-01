#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    bool tf = false;

    for (int i = 1; i < words.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (words[j] == words[i]) {
                tf = true;
                break;
            }
        }
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0])
            tf = true;

        if (tf) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
    }

    return answer;
}
