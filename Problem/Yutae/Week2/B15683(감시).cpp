// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[9][9];
vector<pair<int, int>> v;
int res = 987654321;

void changeRight(int y, int x) {
	for (int j = x; j < M; j++) {
		if (A[y][j] == 6) break;
		else if (A[y][j] == 0) A[y][j] = -1;
	}
}

void changeDown(int y, int x) {
	for (int i = y; i < N; i++) {
		if (A[i][x] == 6) break;
		else if (A[i][x] == 0) A[i][x] = -1;
	}
}

void changeLeft(int y, int x) {
	for (int j = x; j >= 0; j--) {
		if (A[y][j] == 6) break;
		else if (A[y][j] == 0) A[y][j] = -1;
	}
}

void changeUp(int y, int x) {
	for (int i = y; i >= 0; i--) {
		if (A[i][x] == 6) break;
		else if (A[i][x] == 0) A[i][x] = -1;
	}
}

int countZero() {
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] == 0)
				cnt++;

	return cnt;
}

void num1(int d, int y, int x) {
	switch (d){
	case 1:
		changeRight(y, x);
		break;
	case 2:
		changeDown(y, x);
		break;
	case 3:
		changeLeft(y, x);
		break;
	case 4:
		changeUp(y, x);
	default:
		break;
	}
}

void num2(int d, int y, int x) {
	switch (d) {
	case 1:
		changeRight(y, x);
		changeLeft(y, x);
		break;
	case 2:
		changeUp(y, x);
		changeDown(y, x);
		break;
	default:
		break;
	}
}

void num3(int d, int y, int x) {
	switch (d) {
	case 1:
		changeUp(y, x);
		changeRight(y, x);
		break;
	case 2:
		changeRight(y, x);
		changeDown(y, x);
		break;
	case 3:
		changeDown(y, x);
		changeLeft(y, x);
		break;
	case 4:
		changeLeft(y, x);
		changeUp(y, x);
		break;
	default:
		break;
	}
}

void num4(int d, int y, int x) {
	switch (d) {
	case 1:
		changeLeft(y, x);
		changeUp(y, x);
		changeRight(y, x);
		break;
	case 2:
		changeUp(y, x);
		changeRight(y, x);
		changeDown(y, x);
		break;
	case 3:
		changeRight(y, x);
		changeDown(y, x);
		changeLeft(y, x);
		break;
	case 4:
		changeDown(y, x);
		changeLeft(y, x);
		changeUp(y, x);
		break;
	default:
		break;
	}
}

void num5(int y, int x) {
	changeRight(y, x);
	changeDown(y, x);
	changeLeft(y, x);
	changeUp(y, x);
}

void numWhat(int n, int d, int y, int x) {
	switch (n) {
	case 1:
		num1(d, y, x);
		break;
	case 2:
		num2(d, y, x);
		break;
	case 3:
		num3(d, y, x);
		break;
	case 4:
		num4(d, y, x);
		break;
	case 5:
		num5(y, x);
		break;
	default:
		break;
	}
}

void copyArr(int A[9][9], int B[9][9]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = B[i][j];
}

void solution(int cnt) {
	if (cnt == v.size()) {
		res = min(res, countZero());
		return;
	}

	int tmp[9][9];
	int y = v[cnt].first, x = v[cnt].second;

	copyArr(tmp, A);

	for (int i = 1; i < 5; i++) {
		numWhat(A[y][x], i, y, x);
		solution(cnt + 1);
		copyArr(A, tmp);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			if (A[i][j] != 0 && A[i][j] != 6)
				v.push_back(make_pair(i, j));
		}

	solution(0);

	cout << res << "\n";

	return 0;
}
