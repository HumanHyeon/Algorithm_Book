#include <string>
#include <vector>
using namespace std;

int answer;

void checkInput(vector<string>& data, string input) {
    for (auto fetch : data) {
        int kf_distance = input.find(fetch[0]) > input.find(fetch[2]) ? input.find(fetch[0]) - input.find(fetch[2]) : input.find(fetch[2]) - input.find(fetch[0]);
        int friends_number = fetch[4] - '0' + 1;
        if (fetch[3] == '=' && kf_distance != friends_number) return;
        else if (fetch[3] == '<' && kf_distance >= friends_number) return;
        else if (fetch[3] == '>' && kf_distance <= friends_number) return;
    }
    answer++;
}

void dfs(const char kf[8], bool check[8], string input, vector<string>& data) {
    if (input.size() == 8) {
        checkInput(data, input);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (check[i]) continue;
        input += kf[i];
        check[i] = true;
        dfs(kf, check, input, data);
        input.pop_back();
        check[i] = false;
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    const char kakaoFreinds[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    bool check[8] = { false, };
    string input = "";

    for (int i = 0; i < 8; i++) {
        input += kakaoFreinds[i];
        check[i] = true;
        dfs(kakaoFreinds, check, input, data);
        input = "";
        check[i] = false;
    }

    return answer;
}
