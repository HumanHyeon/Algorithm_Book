#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool ck = false;

    while (1) {
        bool visit[30][30] = { false, };

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (board[i][j] == ' ') continue;
                if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
                    visit[i][j] = true;
                    visit[i + 1][j] = true;
                    visit[i][j + 1] = true;
                    visit[i + 1][j + 1] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (visit[i][j]) ck = true;
        if (!ck) break;
        else ck = false;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (visit[i][j]) {
                    for (int k = i - 1; k >= 0; --k) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                    ++answer;
                }
    }

    return answer;
}
