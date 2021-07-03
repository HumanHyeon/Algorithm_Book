#include <iostream>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

typedef struct {
	int x1;
	int x2;
	int y1;
	int y2;
}Pos;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	
	vector<Pos> pos(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &pos[i].x1);
		scanf("%d", &pos[i].y1);
		scanf("%d", &pos[i].x2);
		scanf("%d", &pos[i].y2);
	}
//Alogrithm Part
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = board[i][j];
			if ((i - 1) >= 0) dp[i][j] += dp[i - 1][j];
			if ((j - 1) >= 0) dp[i][j] += dp[i][j - 1];
			if ((i - 1) >= 0 && (j - 1) >= 0) dp[i][j] -= dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int answer;
		int flag = 0;

		if (pos[i].x1 == pos[i].x2 && pos[i].y1 == pos[i].y2) {
			printf("%d\n", board[pos[i].x1 - 1][pos[i].y1 - 1]);
			continue;
		}
		answer = dp[pos[i].x2 - 1][pos[i].y2 - 1];
		if (pos[i].x1 - 2 >= 0) {
			answer -= dp[pos[i].x1 - 2][pos[i].y2 - 1];
			flag++;
		}
		if (pos[i].y1 - 2 >= 0) {
			answer -= dp[pos[i].x2 - 1][pos[i].y1 - 2];
			flag++;
		}
		if (flag == 2)
			answer += dp[pos[i].x1 - 2][pos[i].y1 - 2];
		printf("%d\n", answer);
	}
}
