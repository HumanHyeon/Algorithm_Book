#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    bool flag = false;
    int answer = 0;
	while (flag == false) {
		vector<vector<bool>> visit(m, vector<bool>(n));
		flag = true;
		for (int x = 0; x <m-1;x++) {
			for (int y = 0; y < n - 1; y++) {
				if (board[x][y] == 0)
					continue;
				if ((board[x][y] == board[x][y + 1])&& (board[x][y]== board[x + 1][y])&&(board[x][y]== board[x + 1][y + 1])) {
					visit[x][y] = 1;
					visit[x][y+1] = 1;
					visit[x+1][y] = 1;
					visit[x + 1][y + 1] = 1;
					flag = false;
				}
			}
		}

		for (int x = 0; x < m; x++) {	//제거
			for (int y = 0; y < n; y++) {
				if (visit[x][y]==1) {
					answer++;
					for (int k = x-1; k >=0; k--) {
						board[k + 1][y] = board[k][y];
						board[k][y] = 0;
					}
				}
			}
		}

	}
	return answer;
}
