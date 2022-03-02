https://programmers.co.kr/learn/courses/30/lessons/64065

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> table;
    vector<pair<int, int>> tmp;

    string input = "";
    bool check_input = false;
    for (int i = 0; i < s.size(); i++) 
        if (check_input) {
            if (s[i] >= '0' && s[i] <= '9') input += s[i];
            else {
                table[stoi(input)]++;
                input = "", check_input = false;
            }
        }
        else {
            if (s[i] >= '0' && s[i] <= '9') 
                input += s[i], check_input = true;
        }
    copy(table.begin(), table.end(), back_inserter< vector<pair<int, int>>>(tmp));
    sort(tmp.begin(), tmp.end(), cmp);
    for (auto fetch : tmp) answer.push_back(fetch.first);

    return answer;
}
