//https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>

using namespace std;

static vector<vector<int>> picture;

static int area = 0;

static int M = 0, N = 0;

void FIND(int x, int y)
{
    if (picture[x][y] == 0)
        return;

    area++;

    int cmp = picture[x][y];

    picture[x][y] = 0;

    if (x != 0) 
        if (cmp == picture[x - 1][y])
            FIND(x - 1, y);
    
    if (y != 0) 
        if (cmp == picture[x][y - 1])
            FIND(x, y - 1);

    if (x + 1 != M) 
        if (cmp == picture[x + 1][y])
            FIND(x + 1, y);
    
    if (y + 1 != N) 
        if (cmp == picture[x][y + 1])
            FIND(x, y + 1);  
}

vector<int> solution(int m, int n, vector<vector<int>> Picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    picture = Picture;

    area = 0;

    M = m;
    N = n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] == 0)
                continue;

            FIND(i, j);

            number_of_area++;

            if (max_size_of_one_area < area)
                max_size_of_one_area = area;

            area = 0;
        }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
