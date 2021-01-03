//https://programmers.co.kr/learn/courses/18/lessons/1879
#include <iostream>
#include<vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int large = 0;

    int A = board.size();
    int B = board[0].size();

    if (A == 1 || B == 1)
        return 1;

    else
        for (int i = 1; i < A; i++)       
            for (int j = 1; j < B; j++)
            {
                if (board[i][j] != 0)
                    board[i][j] = min(min(board[i - 1][j - 1], board[i - 1][j]), board[i][j - 1]) + 1;

                if (board[i][j] > large)
                    large = board[i][j];
            }        

    return large * large;
}
