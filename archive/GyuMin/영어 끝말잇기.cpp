//https://programmers.co.kr/learn/courses/30/lessons/12981
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    map<string, bool> map;

    map[words[0]] = true;

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i].front() == words[i - 1].back())
        {
            if (map[words[i]] == true)
            {
                answer.push_back((i % n) + 1);
                answer.push_back((i / n) + 1);
                return answer;
            }

            else
                map[words[i]] = true;
        }

        else
        {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}
