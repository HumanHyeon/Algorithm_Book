#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true) {
        vector<pair<int, int>> table;
        for (int i = 0; i < board.size() - 1; i++) 
            for (int j = 0; j < board[0].size() - 1; j++) 
                if (board[i][j] == ' ' || board[i][j] != board[i + 1][j] || board[i][j] != board[i][j + 1] || board[i][j] != board[i + 1][j + 1]) continue;
                else table.push_back(make_pair(i, j));
        if (table.empty())   break;
        for (auto fetch : table) {
            if (board[fetch.first][fetch.second] != ' ') answer++, board[fetch.first][fetch.second] = ' ';
            if (board[fetch.first + 1][fetch.second] != ' ') answer++, board[fetch.first + 1][fetch.second] = ' ';
            if (board[fetch.first][fetch.second + 1] != ' ') answer++, board[fetch.first][fetch.second + 1] = ' ';
            if (board[fetch.first + 1][fetch.second + 1] != ' ') answer++, board[fetch.first + 1][fetch.second + 1] = ' ';
        }
        for (int i = board.size() - 1; i >= 1; i--) 
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != ' ')  continue;
                int index;
                for (index = i - 1; index >= 0; index--) if (board[index][j] != ' ')  break;
                if (index == -1) continue;
                board[i][j] = board[index][j];
                board[index][j] = ' ';
            }
    }

    return answer;
}
