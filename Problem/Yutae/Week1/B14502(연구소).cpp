// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[9][9];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int cnt = 0;

void bfs() {
	int map_tmp[9][9];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map_tmp[i][j] = map[i][j];

	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map_tmp[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map_tmp[ny][nx] == 0) {
				map_tmp[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	int a = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map_tmp[i][j] == 0)
				a++;
	cnt = (a > cnt) ? a : cnt;
}

void solution(int count) {
	if (count == 3) {
		bfs();
		return;
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solution(count+1);
				map[i][j] = 0;
			}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solution(1);
				map[i][j] = 0;
			}

	cout << cnt << "\n";

	return 0;
}
