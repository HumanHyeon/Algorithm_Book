//https://programmers.co.kr/learn/courses/30/lessons/68645?language=cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;

    int snail[1000][1000];

    int x = 0, y = 0;

    int num = 1;

    int mode = 0;//남서쪽,동쪽,북서쪽

    for (int i = 0; i < n; i++)
        switch (mode)
        {
        case 0://남서
            for (int j = i; j < n; j++)
                snail[x++][y] = num++;
            mode = 1;
            x--;
            y++;
            break;

        case 1://동
            for (int j = i; j < n; j++)
                snail[x][y++] = num++;
            mode = 2;
            x--;
            y -= 2;
            break;

        case 2://북서
            for (int j = i; j < n; j++)
                snail[x--][y--] = num++;
            mode = 0;
            x += 2;
            y++;
            break;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            answer.push_back(snail[i][j]);

    return answer;
}
