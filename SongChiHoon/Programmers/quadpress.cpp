#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> board;
 
void DFS(int x, int y, int Size, vector<int> &answer)
{
    bool Zero = true;
    bool One = true;
    for (int i = x; i < x + Size; i++)
    {
        for (int j = y; j < y + Size; j++)
        {
            if (board[i][j] == 0) One = false;
            if (board[i][j] == 1) Zero = false;
        }
    }
 
    if (Zero == true)
    {
        answer[0]++;
        return;
    }
    if (One == true)
    {
        answer[1]++;
        return;
    }
 
    DFS(x, y, Size / 2, answer);
    DFS(x, y + Size / 2, Size / 2, answer);
    DFS(x + Size / 2, y, Size / 2, answer);
    DFS(x + Size / 2, y + Size / 2, Size / 2, answer);
}
 
vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer(2, 0);
    board = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}