#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(1, 1);
    vector<vector <int>> waterSpore({
        { 1, 2, 3, 4, 5 },
        { 2, 1, 2, 3, 2, 4, 2, 5 },
        { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
    });
    int count[] = { 0, 0, 0 };
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == waterSpore[0][i % waterSpore[0].size()])  count[0]++;
        if (answers[i] == waterSpore[1][i % waterSpore[1].size()])  count[1]++;
        if (answers[i] == waterSpore[2][i % waterSpore[2].size()])  count[2]++;
    }
    
    for (int i = 1; i < 3; i++) {
        if (count[answer[0] - 1] > count[i])    continue;
        else if (count[answer[0] - 1] < count[i])   answer.clear();
        answer.push_back(i + 1);
    }
    return answer;
}

//*max_element
