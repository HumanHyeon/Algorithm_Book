// https://www.acmicpc.net/problem/16935

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, R;
int map[101][101];
int tmp[101][101];
queue<int> q;

void map_copy(int a[101][101], int b[101][101]) {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			a[i][j] = b[i][j];
}

void num1() {
	int up = 0, down = N - 1;

	while (up < down) {
		for (int j = 0; j < M; j++) {
			int tmp2 = map[up][j];
			map[up][j] = map[down][j];
			map[down][j] = tmp2;
		}
		up++;
		down--;
	}
}

void num2() {
	int left = 0, right = M - 1;

	while (left < right) {
		for (int i = 0; i < N; i++) {
			int tmp2 = map[i][left];
			map[i][left] = map[i][right];
			map[i][right] = tmp2;
		}
		left++;
		right--;
	}
}

void num3() {
	memset(tmp, 0, sizeof(tmp));

	int t = N;
	N = M;
	M = t;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = map[t - 1 - j][i];

	map_copy(map, tmp);
}

void num4() {
	memset(tmp, 0, sizeof(tmp));

	int t = M;
	M = N;
	N = t;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = map[j][t - 1 - i];

	map_copy(map, tmp);
}

void num5() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
			tmp[i][j + M / 2] = map[i][j];

	for (int i = 0; i < N / 2; i++)
		for (int j = M / 2; j < M; j++)
			tmp[i + N / 2][j] = map[i][j];

	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			tmp[i][j - M / 2] = map[i][j];

	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M / 2; j++)
			tmp[i - N / 2][j] = map[i][j];

	map_copy(map, tmp);
}

void num6() {
	memset(tmp, 0, sizeof(tmp));

	for (int i = N / 2; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j + M / 2] = map[i][j];

	for (int i = N / 2; i < N; i++)
		for (int j = M / 2; j < M; j++)
			tmp[i - N / 2][j] = map[i][j];

	for (int i = 0; i < N / 2; i++)
		for (int j = M / 2; j < M; j++)
			tmp[i][j - M / 2] = map[i][j];

	for (int i = 0; i < N / 2; i++)
		for (int j = 0; j < M / 2; j++)
			tmp[i + N / 2][j] = map[i][j];

	map_copy(map, tmp);
}

void solution() {
	switch (q.front()) {
	case 1:
		num1();
		break;
	case 2:
		num2();
		break;
	case 3:
		num3();
		break;
	case 4:
		num4();
		break;
	case 5:
		num5();
		break;
	default:
		num6();
		break;
	}

	q.pop();
}

int main() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int num;
	for (int i = 0; i < R; i++) {
		cin >> num;
		q.push(num);
	}

	while(!q.empty())
		solution();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
