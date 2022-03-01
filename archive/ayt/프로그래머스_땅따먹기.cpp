#include <vector>
using namespace std;

int maxSum(vector<vector<int>>& land,int i,int j) {
    int maxs = 0;

    for (int x = 0; x < 4; ++x) {
        if (x != j) 
            maxs = (maxs > land[i][x]) ? maxs : land[i][x];
    }

    return maxs;
}

int solution(vector<vector<int> > land){
    int answer = 0;

    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            land[i][j] += maxSum(land, i - 1, j);
            answer = (answer > land[i][j]) ? answer : land[i][j];
        }
    }

    return answer;
}


/*#include <vector>
using namespace std;

int maxs = 0;

void dfs(vector<vector<int>>& land, int n,int sum, int x) {
    if (land.size() - 1 == n) {
        maxs = (maxs > sum) ? maxs : sum;
        return;
    }

    for (int j = 1; j < 4; ++j) {
        dfs(land, n + 1, sum + land[n + 1][(x + j) % 4], (x + j) % 4);
    }
}

int solution(vector<vector<int> > land){
    for (int i = 0; i < 4; ++i) {
        dfs(land, 0, land[0][i], i);
    }
    int answer = maxs;

    return answer;
}*/
