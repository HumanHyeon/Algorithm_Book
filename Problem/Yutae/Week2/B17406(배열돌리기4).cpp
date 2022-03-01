// https://www.acmicpc.net/problem/17406

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, r, c, s;
int A[51][51];
int small_A[51][51];
int tmp_A[51][51];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int sum = 987654321;
vector <pair<pair<int, int>, int>> v;

void sumA() {
	for (int i = 0; i < N; i++) {
		int tmp = 0;

		for (int j = 0; j < M; j++) {
			tmp += tmp_A[i][j];
		}
		sum = min(sum, tmp);
	}
}

void rotation(int tmp_r, int tmp_c, int tmp_s) {
	memset(small_A, 0, sizeof(small_A));

	int start_y = tmp_r - 1 - tmp_s;
	int start_x = tmp_c - 1 - tmp_s;
	int len = tmp_s * 2 + 1;


	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			small_A[i][j] = tmp_A[i + start_y][j + start_x];

	for (int i = 0; i < len / 2; i++) {
		int y = i, x = i;
		int tmp = small_A[y][x];

		for (int j = 0; j < 4; j++) {
			while (1) {
				int ny = y + dy[j];
				int nx = x + dx[j];

				if (ny < i || nx < i || ny >= len - i || nx >= len - i) break;
				int tmp2 = small_A[ny][nx];
				small_A[ny][nx] = tmp;
				tmp = tmp2;
				y = ny;
				x = nx;
			}
		}
	}

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			tmp_A[i + start_y][j + start_x] = small_A[i][j];
}

void solution() {
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		v.push_back(make_pair(make_pair(r, c), s));
	}

	sort(v.begin(), v.end());

	do {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				tmp_A[i][j] = A[i][j];

		for (int i = 0; i < K; i++){
			rotation(v[i].first.first, v[i].first.second, v[i].second);
		}

		sumA();
	} while (next_permutation(v.begin(), v.end()));

	cout << sum;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	solution();

	return 0;
}
