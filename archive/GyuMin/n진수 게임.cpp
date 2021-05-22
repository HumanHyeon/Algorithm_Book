//https://programmers.co.kr/learn/courses/30/lessons/17687
#include <string>
#include <vector>

using namespace std;

vector <string> set = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };

string solution(int n, int t, int m, int p)
{
    string answer = "";

    string sub = "";

    for (int i = 0; i <= 100000; i++)
    {
        int num = i;

        if (num >= n)
        {
            while (num >= n)
            {
                sub = set[num % n] + sub;

                num = num / n;
            }

            sub = set[num] + sub;
        }

        else
            sub = set[num];

        answer += sub;

        sub = "";
    }

    sub = answer;
    answer = "";

    for (int i = p; answer.size() != t; i += m)
        answer += sub[i - 1];

    return answer;
}
