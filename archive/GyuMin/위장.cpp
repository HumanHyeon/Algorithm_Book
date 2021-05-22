//https://programmers.co.kr/learn/courses/30/lessons/42578#
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> a, vector<string> b) 
{
        return a[1] < b[1];
}

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    int x = 1;

    vector<int> cat;

    sort(clothes.begin(), clothes.end(), compare);

    for (int i = 0; i < clothes.size() - 1; i++)
        if (clothes[i][1] == clothes[i + 1][1])
            x++;

        else
        {
            cat.push_back(x + 1);
            x = 1;
        }

    cat.push_back(x + 1);

    for (int i = 0; i <= cat.size(); i++)
        answer *= cat[i];

    answer--;

    return answer;
}
