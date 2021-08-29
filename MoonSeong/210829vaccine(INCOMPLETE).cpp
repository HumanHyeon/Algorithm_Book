#include <iostream>
#include <vector>
#include <set>

#pragma warning (disable:4996)
using namespace std;

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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (before[i][j] == after[i][j])
                continue;
            else {
                auto it = pool.find(pair(i, j));
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
    



}

void push(int i, int j, set<pair<int, int>>& pool, vector<vector<int>>& before, vector<vector<int>>& after, int bVal, int aVal) {
    set<pair<int, int>>::iterator it[5];
    it[0] = pool.find(pair(i, j));
    it[1] = pool.find(pair(i+1, j));
    it[2] = pool.find(pair(i, j+1));
    it[3] = pool.find(pair(i-1, j));
    it[4] = pool.find(pair(i, j-1));
    
    

}
