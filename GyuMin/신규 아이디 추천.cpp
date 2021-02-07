//https://programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
#include <vector>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    string sub = "";

    for (int i = 0; i < new_id.size(); i++)
        if ((new_id[i] >= 'A') && (new_id[i] <= 'Z'))
            new_id[i] = tolower(new_id[i]);
    //1
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((new_id[i] >= 'a') && (new_id[i] <= 'z'))
            answer.push_back(new_id[i]);

        else if ((new_id[i] >= '0') && (new_id[i] <= '9'))
            answer.push_back(new_id[i]);

        else if (new_id[i] == '-')
            answer.push_back(new_id[i]);

        else if (new_id[i] == '_')
            answer.push_back(new_id[i]);

        else if (new_id[i] == '.')
            answer.push_back(new_id[i]);
    }
    //2
    for (int i = 0; i < answer.size(); i++)
    {
        if ((answer[i] == '.') && (answer[i + 1] == '.'));

        else
            sub += answer[i];
    }
    //3
    if (sub[0] == '.')
        sub = sub.substr(1, sub.size() - 1);

    if (sub[sub.size() - 1] == '.')
        sub.pop_back();
    //4
    if (sub.size() == 0)
        sub = "a";
    //5
    if (sub.size() >= 16)
        sub = sub.substr(0, 15);

    if (sub[sub.size() - 1] == '.')
        sub.pop_back();
    //6
    if (sub.size() <= 2)
        while (sub.size() != 3)
            sub += sub[sub.size() - 1];
    //7
    answer = sub;

    return answer;
}
