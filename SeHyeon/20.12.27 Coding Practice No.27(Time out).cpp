#include <algorithm>
#include <vector>
using namespace std;

vector<int> largeValueElement;
int maxValue = 0;

bool promising(vector<vector<int>>& land, int accumulate, int level) {
    for (int i = level; i < land.size(); i++)    accumulate += largeValueElement[i];
    if (accumulate > maxValue)    return true;
    else return false;
}

void dfs(vector<vector<int>>& land, int before, int accumulate, int level = 1) {
    if (level == land.size()) {
        if (maxValue < accumulate) maxValue = accumulate;
        return;
    }
    for (int i = 0; i < 4; i++) 
        if (before == i)  continue;
        else if (promising(land, accumulate, level)) dfs(land, i, accumulate + land[level][i], level + 1);
}

int solution(vector<vector<int> > land){
    for (auto valueList : land) largeValueElement.push_back(*max_element(valueList.begin(), valueList.end()));
    for (int i = 0; i < 4; i++) dfs(land, i, land[0][i]);
    return maxValue;
}
