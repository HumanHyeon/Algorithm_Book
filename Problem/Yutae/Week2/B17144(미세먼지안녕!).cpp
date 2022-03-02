// https://www.acmicpc.net/problem/17144

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int R, C, T;
int A[51][51];
int tmp_A[51][51];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int check_num() {
	int res = 0;

	for(int i=0;i<R;i++)
		for (int j = 0; j < C; j++)
			if (A[i][j] != -1) res += A[i][j];

	return res;
}

void step1(int y, int x) {
	int n = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		else if (ny == v[0].first && nx == v[0].second) continue;
		else if (ny == v[1].first && nx == v[1].second) continue;

		tmp_A[ny][nx] += (A[y][x] / 5);
		n++;
	}

	tmp_A[y][x] += A[y][x] - (A[y][x] / 5 * n);
}

void step2_up() {
	int y = v[0].first, x = v[0].second;

	int ddy[4] = { 0,-1,0,1 };
	int ddx[4] = { 1,0,-1,0 };

	for (int i = 0; i < 4; i++) {
		while (1) {
			int ny = y + ddy[i];
			int nx = x + ddx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) break;
			else if (ny == v[0].first && nx == v[0].second) break;
			
			if (A[y][x] != -1)
				tmp_A[ny][nx] = A[y][x];
			else
				tmp_A[ny][nx] = 0;

			y = ny;
			x = nx;
		}
	}
}

void step2_down() {
	int y = v[1].first, x = v[1].second;

	int ddy[4] = { 0,1,0,-1 };
	int ddx[4] = { 1,0,-1,0 };

	for (int i = 0; i < 4; i++) {
		while (1) {
			int ny = y + ddy[i];
			int nx = x + ddx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) break;
			else if (ny == v[1].first && nx == v[1].second) break;
			
			if (A[y][x] != -1)
				tmp_A[ny][nx] = A[y][x];
			else
				tmp_A[ny][nx] = 0;

			y = ny;
			x = nx;
		}
	}
}

void copy_A(int A[51][51], int B[51][51]) {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (A[i][j] != -1) A[i][j] = B[i][j];
}

void solution() {
	while (T--) {
		memset(tmp_A, 0, sizeof(tmp_A));

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (A[i][j] != -1 && A[i][j] != 0)
					step1(i, j);

		copy_A(A, tmp_A);

		step2_up();
		step2_down();

		copy_A(A, tmp_A);
	}
}

int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1) v.push_back(make_pair(i, j));
		}

	solution();

	cout << check_num() << "\n";

	return 0;
}
