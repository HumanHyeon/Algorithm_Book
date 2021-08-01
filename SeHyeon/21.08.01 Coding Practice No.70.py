https://www.acmicpc.net/problem/13460
  
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#pragma warning (disable : 4996)
using namespace std;

typedef struct {
	int bx, by;
	int rx, ry;
}ballPos;

typedef struct {
	vector<vector<char>> board;
	ballPos bp;
	int bfDirect;
}node;

int N, M;
int answer = 987654321;

int dx[] = { -1, 1, 0, 0 }; //좌 우 상 하
int dy[] = { 0, 0, -1, 1 };

void bfs(queue<node> info) {

}

int move(vector<vector<char>>& board, int direction, ballPos& bp) {	//이동되면 1, 이동되지 않으면 0
	int bx, by, rx, ry;

	bx = bp.bx, by = bp.by, rx = bp.rx, ry = bp.ry;
	
}

void solution(vector<vector<char>> board, ballPos bp) {
	queue<node> info;

	for (int i = 0; i < 4; i++) {
		node input;
		vector<vector<char>> tmp;
		if (!move(tmp, i, bp))
			continue;
		input.board = tmp;
		input.bfDirect = i;
		input.bp = bp;
		info.push(input);
	}
	bfs(info);
}

int main() {
	ballPos bp = { 0, 0, 0, 0 };
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M, ' '));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				bp.rx = j;
				bp.ry = i;
			}
			if (board[i][j] == 'B') {
				bp.bx = j;
				bp.by = i;
			}
		}
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//		printf("%c ", board[i][j]);
	//	putchar('\n');
	//}
	solution(board, bp);
	cout << answer;
}
