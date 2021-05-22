//https://programmers.co.kr/learn/courses/30/lessons/17679
#include <string>
#include <vector>

using namespace std;

int pop(int m, int n, vector<string> board)
{
    bool poped = false;

    int pop_count = 0;
    
    string can_pop[30][30];

    for (int i = 0; i < m-1; i++)
        for (int j = 0; j < n - 1; j++)
        {
            if (board[i][j] == '#')
                continue;

            if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1])
            {
                can_pop[i][j] = "#";
                can_pop[i + 1][j] = "#";
                can_pop[i][j + 1] = "#";
                can_pop[i + 1][j + 1] = "#";
                poped = true;
            }
        }
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (can_pop[i][j] == "#")
            {
                pop_count++;

                for (int a = i - 1; a >= 0; a--)
                {
                    board[a + 1][j] = board[a][j];
                    board[a][j] = '#';
                }
            }

    if (poped)
        return pop_count + pop(m, n, board);
    else
        return pop_count;
}

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;

    answer = pop(m, n, board);

    return answer;
}
