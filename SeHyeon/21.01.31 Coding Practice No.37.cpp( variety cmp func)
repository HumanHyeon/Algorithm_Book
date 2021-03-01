#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> table;

void dfs(const string fetch, const int course, int start, string accumulate = "") {
    if (accumulate.size() == course) {
        sort(accumulate.begin(), accumulate.end());
        if (table.find(accumulate) == table.end()) table[accumulate] = 0;
        return;
    }
    if (start == fetch.size() - 1)  return;
    dfs(fetch, course, start + 1, accumulate);
    dfs(fetch, course, start + 1, accumulate += fetch[start + 1]);
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second < b.second) return true;
    return false;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) {
        table.clear();
        for (auto fetch : orders) {
            if (fetch.size() < course[i])    continue;
            for (int j = 0; j < fetch.size() - course[i] + 1; j++) {
                string accumulate = "";
                accumulate += fetch[j];
                dfs(fetch, course[i], j, accumulate);
            }
        }
        for (auto iter = table.begin(); iter != table.end(); iter++) 
            for (auto order : orders) {
                bool check = true;
                for (int j = 0; j < course[i]; j++) 
                    if (order.find((*iter).first[j]) == string::npos) {
                        check = false;
                        break;
                    }
                if (check) table[(*iter).first]++;
            }
        int max_Value = (*max_element(table.begin(), table.end(), cmp)).second;
        if (max_Value >= 2) 
            for (auto fetch : table) 
                if (fetch.second == max_Value)   answer.push_back(fetch.first);
    }
    sort(answer.begin(), answer.end());

    return answer;
}
