//https://programmers.co.kr/learn/courses/30/lessons/12913?language=cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int MAX = land.size();

    for (int i = 1; i < MAX; i++)
    {
        land[i][0] += max(max(land[i - 1][1], land[i - 1][2]), land[i - 1][3]);
        land[i][1] += max(max(land[i - 1][0], land[i - 1][2]), land[i - 1][3]);
        land[i][2] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][3]);
        land[i][3] += max(max(land[i - 1][0], land[i - 1][1]), land[i - 1][2]);
    }

    return max(max(max(land[MAX - 1][0], land[MAX - 1][1]), land[MAX - 1][2]), land[MAX - 1][3]);
}
