#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> key;

void dfs(string& index, int start, int& size, string accumulate) {
    if (accumulate.size() == size)
        if(find(key.begin(), key.end(), accumulate) == key.end())   key.push_back(accumulate);
    if (start == index.size() - 1)  return;
    dfs(index, start + 1, size, accumulate);
    dfs(index, start + 1, size, accumulate += index[start + 1]);
}

bool minimalism(vector<string> candiate_key, string compare) {
    for (auto fetch : candiate_key) {
        int overlap_count = 0;
        for (int i = 0; i < fetch.size(); i++) 
            if (compare.find(fetch[i]) != string::npos) overlap_count++;
        if (overlap_count == fetch.size())   return true;
    }
    return false;
}

int solution(vector<vector<string>> relation) {
    vector<string> candiate_key;
    
    string index = "";
    for (int i = 0; i < relation[0].size(); i++) index += to_string(i);
    for (int size = 1; size <= relation[0].size(); size++) 
        for (int i = 0; i < relation[0].size(); i++) {
            string accumulate = "";
            accumulate += index[i];
            dfs(index, i, size, accumulate);
        }

    for (auto fetch : key) {
        bool check = minimalism(candiate_key, fetch);
        if (check)    continue;

        vector<string> table(relation.size());
        for (auto column : fetch) {
            int insert = 0;
            for (int i = 0; i < relation.size(); i++)  table[insert++] += relation[i][column - '0'];
        }
        check = true;
        for (int i = 0; i < table.size(); i++) {
            for (int j = i + 1; j < table.size(); j++)
                if (table[i] == table[j]) {
                    check = false;  break;
                }
            if (!check)   break;
        }
        if (check)  candiate_key.push_back(fetch);
    }

    return candiate_key.size();
}
