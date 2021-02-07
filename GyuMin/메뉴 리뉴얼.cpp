//https://programmers.co.kr/learn/courses/30/lessons/72411?language=cpp
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> MAP;

int MAX = 0;

vector<string> answer;

string comb;

void menu_of_course(string order, int course, int ind)
{
    if (course == comb.size())
    {
        MAP[comb]++;

        if (MAX < MAP[comb])
            MAX = MAP[comb];
    }

    else if (ind == order.size())
    {
    }

    else
    {
        comb.push_back(order[ind]);
        menu_of_course(order, course, ind + 1);

        comb.pop_back();
        menu_of_course(order, course, ind + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (int j = 0; j < course.size(); j++)
    {
        for (int i = 0; i < orders.size(); i++)
            menu_of_course(orders[i], course[j], 0);

        for (auto x : MAP)
        {
            if (MAX < 2)
                break;

            if (x.second == MAX)
                answer.push_back(x.first);
        }

        comb.clear();
        MAP.clear();
        MAX = 0;
    }

    sort(answer.begin(), answer.end());

    return answer;
}
