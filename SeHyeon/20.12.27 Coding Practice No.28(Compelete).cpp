#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    if (board.size() == 1 || board[0].size() == 1) {
        for (int x = 0; x < board[0].size(); x++)    if (board[0][x]) return 1;
        for (int y = 0; y < board.size(); y++)  if (board[y][0]) return 1;
        return 0;
    }
    for (int y = 1; y < board.size(); y++)
        for (int x = 1; x < board[0].size(); x++) {
            if (!board[y][x])    continue;
            int minValue = min(board[y - 1][x - 1], board[y - 1][x]);
            minValue = min(minValue, board[y][x - 1]);
            board[y][x] = ++minValue;
            if (minValue > answer)   answer = minValue;
        }
    return answer * answer;
}
