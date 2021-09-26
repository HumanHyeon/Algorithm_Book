https://programmers.co.kr/learn/courses/30/lessons/85002

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double calWinRate(string record) {
    return (double)count(record.begin(), record.end(), 'W') / (record.size() - 1) * 100;
}

int calHeavy(vector<int> w, string record) {
    int index = -1;

    while (index != w.size()) {

        index = find(w.begin(), w.end(), 100);
    }
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer(weights.size());
    vector<double> winRate(weights.size());

    for (int i = 0; i < head2head.size(); i++)
        winRate[i] = calWinRate(head2head[i]);
    

    return answer;
}

int main() {
    string str = "NWWL";

    cout << calWinRate(str);
}
