#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> p;
    int si = stages.size();

    for (int i = 0; i < N; ++i) {
        double tmp = 0;
        for (int j = 0; j < stages.size(); ++j)
            if (stages[j] == i + 1) ++tmp;
        if (tmp == 0) p.push_back(make_pair(0, i + 1));
        else p.push_back(make_pair(tmp / si, i + 1));
        si -= tmp;
    }
    
    sort(p.begin(), p.end(), compare);
    for (auto elem : p) answer.push_back(elem.second);

    return answer;
}
