#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(), stages.end());

    auto point = stages.begin();
    int stage_index = 0;
    int count = 0;
    int temp = 0;
    int users = stages.size();
    int *failure = new int[N];

    for (auto i = stages.begin(); i == stages.end(); i = point) {
        temp = *i;
        i++;

        if(temp == *i) {
            count++;
        }
        else {
            point = i;
        }

        failure[stage_index] = count;

    }

    for (int i = 0; i < N; i++) {
        cout << failure[i];
    }
    
    return answer;
}