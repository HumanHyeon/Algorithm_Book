https://programmers.co.kr/learn/courses/30/lessons/83201

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for (int i = 0; i < scores[0].size(); i++) {
        vector<int> fetch;
        int selfScore = scores[i][i];
        int sum = 0;
        bool maxChk = true, minChk = true;

        for (int j = 0; j < scores[0].size(); j++) {
            if (j == i)
                continue;
            fetch.push_back(scores[j][i]);
        }
        if (*max_element(fetch.begin(), fetch.end()) < selfScore)
            maxChk = false;
        if (*min_element(fetch.begin(), fetch.end()) > selfScore)
            minChk = false;
        if (maxChk && minChk)
            fetch.push_back(selfScore);

        sum = accumulate(fetch.begin(), fetch.end(), 0) / (fetch.size() * 10);
        answer += "FFFFFDDCBA"[sum];
    }
    
    return answer;
}
