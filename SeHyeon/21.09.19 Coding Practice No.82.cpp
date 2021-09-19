https://programmers.co.kr/learn/courses/30/lessons/86048

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> enter;
vector<int> leave;

bool first_rule(int a, int b) {
    int a_pos, b_pos;

    a_pos = find(leave.begin(), leave.end(), a) - leave.begin();
    b_pos = find(leave.begin(), leave.end(), b) - leave.begin();
    return (a_pos > b_pos);
}

bool second_rule(int a, int b, int bIndex) {
    queue<int> table;

    int std = find(leave.begin(), leave.end(), a) - leave.begin();

    if (bIndex + 1 < enter.size())
        for (int i = bIndex + 1; i < enter.size(); i++) 
            table.push(enter[i]);
    while (!table.empty()) {
        int cmp = find(leave.begin(), leave.end(), table.front()) - leave.begin();

        if (cmp < std)
            return true;
        table.pop();
    }
    return false;
}

vector<int> solution(vector<int> e, vector<int> l) {
    vector<int> answer(enter.size());
    
    enter = e;
    leave = l;
    for (int i = 0; i < enter.size(); i++) {
        for (int j = i + 1; j < leave.size(); j++) {
            bool check1, check2 = false;
            
            check1 = first_rule(enter[i], enter[j]);
            if (!check1)
                check2 = second_rule(enter[i], enter[j], j);
            if (check1 || check2) {
                answer[enter[i] - 1]++;
                answer[enter[j] - 1]++;
            }
        }
    }

    return answer;
}
