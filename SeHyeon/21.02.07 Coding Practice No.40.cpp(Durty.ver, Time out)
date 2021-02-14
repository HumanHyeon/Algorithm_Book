#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (auto fetch : query) {
        int answerInput = 0;
        string input = "";
        vector<string> queryInfo;
        for (int i = 0; i < fetch.size(); i++) {
            if (fetch[i] == ' ') {
                if (input == "and") {
                    input = ""; continue;
                }
                queryInfo.push_back(input);
                input = "";
            }
            else input += fetch[i];
            if (i == fetch.size() - 1)   queryInfo.push_back(input);
        }
        for (int i = 0; i < info.size(); i++) {
            bool check = true;
            int index = 0;
            string cmp = "";
            for (int j = 0; j < info[i].size(); j++) {
                if (info[i][j] == ' ') {

                    if (queryInfo[index] == "-");
                    else if (queryInfo[index] != cmp) { check = false; break; }
                    index++;
                    cmp = "";
                }
                else cmp += info[i][j];
                if (j == info[i].size() - 1) {
                    if (stoi(queryInfo[index]) > stoi(cmp)) { check = false; break; }
                    else break;
                }
            }
            if (check) answerInput++;
        }
        answer.push_back(answerInput);
    }

    return answer;
}
