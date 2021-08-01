#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int oy, ox;
int by, bx;
int ry, rx;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void solution(vector<vector<char>> a, int count, int& m) {
	if (count >= 10) {
		m = -1;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			count++;

			while (a[ry + dy[i]][rx + dx[i]] == '.') {
				ry += dy[i];
				rx += dx[i];
				if (ry == oy && rx == ox) {
					m = min(count, m);
					return;
				}
			}

			while (a[by + dy[i]][bx + dx[i]] == '.') {
				by += dy[i];
				bx += dx[i];
				if (by == oy && bx == ox) {
					m = 987654321;
					return;
				}
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> a(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			if (a[i][j] == 'O') oy = i, ox = j;
			if (a[i][j] == 'B') by = i, bx = j;
			if (a[i][j] == 'R') ry = i, rx = j;
		}
	}

	int m = 10;
	solution(a, 0, m);

	cout << m << endl;

	return 0;
}
