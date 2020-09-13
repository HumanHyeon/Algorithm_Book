#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int startLine = 0;
    for (int i = 0; i < participant.size(); i++) {
        bool check = false;
        for (int j = startLine; j < completion.size(); j++) {
            if (participant[i][0] < completion[j][0]) {
                break;
            }
            if (participant[i] == completion[j]) {
                completion[j] = "";
                check = true;
                break;
            }
        }
        if (!check)  return participant[i];
    }
    return "";
}
