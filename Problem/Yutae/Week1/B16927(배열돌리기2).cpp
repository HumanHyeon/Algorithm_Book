// https://www.acmicpc.net/problem/16927

#include <iostream>
#include <cstring>

using namespace std;

int N, M, R;
int A[301][301] = { 0, };

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void rotation(int i,int cycle) {
	int rot = R % cycle;

	while(rot--) {
		int y = i, x = i;
		int tmp = A[y][x];

		for (int j = 0; j < 4; j++) {
			while (1) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny < i || nx < i || ny >= N - i || nx >= M - i) break;
				int tmp2 = A[ny][nx];
				A[ny][nx] = tmp;
				tmp = tmp2;
				y = ny;
				x = nx;
			}
		}
	}
}

int main() {
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	int n = N, m = M;

	for (int i = 0; i < N / 2; i++) {
		rotation(i, 2 * (n + m - 2));
		n -= 2;
		m -= 2;
		if (2 * (n + m - 2) == 0) break;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}
