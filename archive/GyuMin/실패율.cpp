//https://programmers.co.kr/learn/courses/30/lessons/42889#qna
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
    if (a.second == b.second) 
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;

    map<int, double> map;

    int people = stages.size();

    double x=0;

    double dou;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < stages.size(); j++)
            if (stages[j] == i)
                x++;

        if (x == 0)
            map[i] = 0;

        else
        {
            dou = x / people;

            map[i] = dou;

            people -= x;
        }

        x = 0;
    }

    vector<pair<int, double>> vec (map.begin(),map.end());

    sort(vec.begin(), vec.end(), cmp);

    for (auto st : vec)
        answer.push_back(st.first);

    return answer;
}
