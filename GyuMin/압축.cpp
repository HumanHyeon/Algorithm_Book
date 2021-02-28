//https://programmers.co.kr/learn/courses/30/lessons/17684#
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> MAP;

int NUM = 1;

vector<int> solution(string msg)
{
    vector<int> answer;

    string temp = "";

    for (; NUM < 27; NUM++)
    {
        temp += 'A' + NUM - 1;
        MAP[temp] = NUM;
        temp = "";
    }

    while (msg.size() != 0)
    {
        if (msg.size() == 1)
        {
            answer.push_back(MAP[msg]);
            break;
        }

        else
        {
            string buf = "";

            for (int i = 0; i < msg.size(); i++)
            {
                buf += msg[i];

                if (MAP[buf + msg[i + 1]] == 0)
                {
                    MAP[buf + msg[i + 1]] = NUM;               
                    NUM++;

                    break;
                }
            }

            answer.push_back(MAP[buf]);

            for (int i = 0; i < buf.size(); i++)
                msg.erase(0,1);
        }
    }
    return answer;
}
