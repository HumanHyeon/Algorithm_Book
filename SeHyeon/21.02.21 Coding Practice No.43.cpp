#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& A, const pair<string, int>& B) {
    if (A.first.size() < B.first.size()) return true;
    return false;
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dictionary;
    int dic_number = 1;

    for (char key = 'A'; dic_number <= 26; dic_number++) {
        string input = "";
        input += key++;
        dictionary[input] = dic_number;
    }

    for (int i = 0; i < msg.size(); ) {
        string w = "", c;
        int maxSize = max_element(dictionary.begin(), dictionary.end(), cmp)->first.size(), wSize = 1;

        for (int j = maxSize; j >= 1; j--) {
            if (dictionary.find(msg.substr(i, j)) != dictionary.end()) {
                wSize = j;
                break;
            }
        }
        w = msg.substr(i, wSize);
        i + wSize < msg.size() ? c = msg.substr(i + wSize, 1) : c = "";
        i += wSize;
        answer.push_back(dictionary.find(w)->second);
        if (c != "") dictionary[w + c] = dic_number++;
    }

    return answer;
}
