#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (auto fetch : query) {
        int answerInput = 0;
        stringstream ss(fetch);
        string input;
        vector<string> queryInfo;
        while (ss >> input) {
            if (input == "and") continue;
            queryInfo.push_back(input);
        }
        for (int i = 0; i < info.size(); i++) {
            bool check = true;
            int j = 0;
            stringstream s2(info[i]);
            while (s2 >> input) {
                if (j == 4) {
                    if (stoi(queryInfo[j]) > stoi(input)) { check = false; break; }
                    else break;
                }
                if (queryInfo[j] == "-") { j++; continue; }
                if (queryInfo[j] != input) { check = false; break; }
                j++;
            }
            if (check) answerInput++;
        }
        answer.push_back(answerInput);
    }

    return answer;
}
