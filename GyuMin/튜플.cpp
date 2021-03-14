//https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<string>a, vector<string>b)
{
    return a.size() < b.size();
}

vector<int> solution(string s)
{
    vector<int> answer;

    vector<vector<string>> set;

    vector<string>sub;

    string a;

    for (int i = 1; i < s.size() - 1; i++)
    {
        if ((s[i] >= '1') && (s[i] <= '9'))
            a.push_back(s[i]);

        else if (s[i] == ',')
        {
            sub.push_back(a);
            a.clear();
        }

        else if (s[i] == '}')
        {
            sub.push_back(a);
            set.push_back(sub);
            a.clear();
            sub.clear();
            i++;
        }
    }

    sort(set.begin(), set.end(),cmp);

    answer.push_back(stoi(set[0][0]));

    vector<string>::iterator it;

    for (int i = 1; i < set.size(); i++)
        for (int j = 0; j < set[i].size(); j++)
        {
            it = find(set[i-1].begin(), set[i-1].end(), set[i][j]);

            if (it != set[i-1].end())
                continue;

            else
                answer.push_back(stoi(set[i][j]));
        }

    return answer;
}
