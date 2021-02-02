#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> v;
    sort(stages.begin(), stages.end());
    
    int user = stages.size();
    int finish_count = 0;
    int nowuser;
    int *above = new int[N];
    double temp;

    for(int i = 0; i < N; i++) {
        user -= finish_count;
        if(user >= 1) {
            finish_count = count(stages.begin(), stages.end(), i+1);
            temp = finish_count / float(user);
            v.push_back(make_pair(i+1, temp));
        }
        else {
            v.push_back(make_pair(i+1, 0));
        }
        
    }

    stable_sort(v.begin(), v.end(), [](const auto& a, const auto& b) {return a.second > b.second; });
    
    for(auto it = 0; it < N; it++) {
        answer.push_back(v[it].first);
    }

    return answer;
}