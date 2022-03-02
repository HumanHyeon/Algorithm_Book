#include <iostream>
#include <vector>
#include <set>

#pragma warning (disable:4996)
using namespace std;

void push(int i, int j, set<pair<int, int>>& pool, vector<vector<int>>& before, vector<vector<int>>& after, int bVal, int aVal);

int main() {
    //input
    int n, m;   //세로 n, 가로 m
    scanf("%d %d", &n, &m);

    vector<vector<int>> before(n);
    vector<vector<int>> after(n);

    for (int i = 0; i < n; i++) {
        before[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &before[i][j]);
    }
    for (int i = 0; i < n; i++) {
        after[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &after[i][j]);
    }
    
    //procedure
    set<pair<int, int>> pool;
    bool diff = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (before[i][j] == after[i][j])
                continue;
            else {
                diff = true;
                auto it = pool.find(pair<int, int>(i, j));
                if (it == pool.end()) { //not found
                    if (pool.empty()) {     //pool is empty
                        push(i, j, pool, before, after, before[i][j], after[i][j]);
                    }
                    else {                  //pool is NOT empty
                        cout << "NO";
                        return 0;
                    }
                }
                else {                  //found
                    continue;
                }
            }
        }
    }

    if (!diff) { 
        cout << "YES";
        return 0;
    }

    auto it = pool.begin();
    int bVal = before[it->first][it->second];
    int aVal = after[it->first][it->second];
    for (; it != pool.end(); it++)
        if (aVal != after[it->first][it->second] || bVal != before[it->first][it->second]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}

void push(int i, int j, set<pair<int, int>>& pool, vector<vector<int>>& before, vector<vector<int>>& after, int bVal, int aVal) {
    pool.insert(pair<int, int>(i, j));
    set<pair<int, int>>::iterator it[4];
    pair<int, int> dir4[4] = {pair<int, int>(i+1, j), pair<int, int>(i, j+1), pair<int, int>(i-1, j), pair<int, int>(i, j-1)};
    for (int k = 0; k < 4; k++)
        it[k] = pool.find(dir4[k]);
    
    for (int k = 0; k < 4; k++) {
        if (it[k] != pool.end())    //found
            continue;
        if (dir4[k].first < 0 || before.size() <= dir4[k].first || dir4[k].second < 0 || before[0].size() <= dir4[k].second)  //Out Of Range
            continue;
        if (before[dir4[k].first][dir4[k].second] == bVal && after[dir4[k].first][dir4[k].second] == aVal)
            push(dir4[k].first, dir4[k].second, pool, before, after, bVal, aVal);
    }

}
