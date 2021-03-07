//https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string  KAKAO = { "ACFJMNRT" };

int answer = 0;

bool compare(char first, char second, char sym, int con, string KAKAO)
{
    int dis;

    dis = KAKAO.find(first) - KAKAO.find(second);

    dis = abs(dis) - 1;

    switch (sym)
    {
    case '>':
        return dis > con;

    case '<':
        return dis < con;

    case '=':
        return dis == con;
    }
}

int solution(int n, vector<string> data)
{
    answer = 0;

    do
    {
        bool pos = true;

        for (int i = 0; i < data.size(); i++)
        {
            int DIS = data[i][4] - '0';

            if (compare(data[i][0], data[i][2], data[i][3], DIS, KAKAO))
                continue;

            pos = false;
            break;
        }

        if (pos)
            answer++;
    } while (next_permutation(KAKAO.begin(), KAKAO.end()));

    return answer;
}
