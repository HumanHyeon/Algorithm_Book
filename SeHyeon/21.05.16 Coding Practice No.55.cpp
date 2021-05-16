https://programmers.co.kr/learn/courses/30/lessons/12952

#include <cstdbool>
#include <cstdlib>
#include <cstring>
#include <cmath>

int     g_answer;

bool    promising(int *board, int last_index, int position)
{
    int i;
    
    i = 0;
    while (i < last_index + 1)
    {
        if ((board[i] == position) || (last_index + 1 - i == abs(position - board[i])))
            return (false);
        i++;    
    }
    return (true);
}

void    dfs(int *board, int last_index, int finish)
{
    int position;
    
    if (last_index + 1 == finish)
    {
        g_answer++;
        return ;
    }
    position = 0;
    while (position < finish)
    {
        if (promising(board, last_index, position))
        {
            board[last_index + 1] = position;
            dfs(board, last_index + 1, finish);
        }
        position++;
    }
}

int     solution(int n) {
    int *board;
    int position;
    
    g_answer = 0;
    board = (int *)malloc(sizeof(int) * n);
    memset(board, -1, sizeof(int) * n);
    position = 0;
    while (position < n)
    {
        board[0] = position;
        dfs(board, 0, n);
        position++;
    }    
    return (g_answer);
}
