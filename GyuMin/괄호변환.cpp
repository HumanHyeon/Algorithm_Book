//https://programmers.co.kr/learn/courses/30/lessons/60058#
#include <string>
#include <vector>

using namespace std;

string answer = "";

string check(string p)
{
    if (p.size() == 0)
        return "";

    int x = 1;

    int i;

    string u, v;

    for (i = 1; x != 0; i++)
    {
        if (p[i] == p[0])
            x++;

        else
            x--;
    }

    u = p.substr(0, i);
    v = p.substr(i, p.size() - i);

    if (u[0] == '(')
        return u + check(v);

    else
    {
        string rev = u.substr(1, u.size() - 2);

        for (int i = 0; i < rev.size(); i++)
            if (rev[i] == '(')
                rev[i] = ')';

            else
                rev[i] = '(';

        return "(" + check(v) + ")" + rev;
    }
}

string solution(string p) 
{
    if (p.size() == 0)
        return answer;
   
    else
        answer = check(p);

    return answer;
}
