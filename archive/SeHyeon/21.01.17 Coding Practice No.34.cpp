#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> table;
    vector<int> answer;
    int count[502] = { 0, }, reachPlayer = stages.size();

    for (auto tmp : stages) count[tmp]++;
    for (int i = 1; i <= N; i++) {
        if (reachPlayer == 0) {
            table.push_back(make_pair(0, i));
            continue;
        }
        double input = count[i] / (double)reachPlayer;
        reachPlayer -= count[i];
        table.push_back(make_pair(input, i));
    }
    stable_sort(table.begin(), table.end(), cmp);
    for(int i = 0; i < table.size(); i++) answer.push_back(table[i].second);

    return answer;
}

//계수 정렬에서 착안
