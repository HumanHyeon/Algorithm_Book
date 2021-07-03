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

	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int y = pos[i].y1 - 1; y < pos[i].y2; y++)
			for (int x = pos[i].x1 - 1; x < pos[i].x2; x++) 
				sum += board[y][x];
		printf("%d\n", sum);
	}
}
