// https://www.acmicpc.net/problem/16926

#include <iostream>
#include <cstring>

using namespace std;

int N, M, R;
int A[301][301] = { 0, };
int B[301][301] = { 0, };

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void rotation() {
	for (int i = 0; i < N / 2; i++) {
		int y = i, x = i;

		for (int j = 0; j < 4; j++) {
			while (1) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny < i || nx < i || ny >= N - i || nx >= M - i) break;
				B[ny][nx] = A[y][x];
				y = ny;
				x = nx;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = B[i][j];

	memset(B, 0, sizeof(B));
}

int main() {
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	while (R--) {
		rotation();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}
