// https://www.acmicpc.net/problem/16236

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

struct Shark {
	int y;
	int x;
	int eat;
	int size;
};

int N, res = 0;
int A[21][21];
vector<pair<pair<int, int>, int>> v;
Shark shark;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cache[21][21];

void bfs(int start_y, int start_x) {
	memset(cache, 0, sizeof(cache));
	int min_eat = 987654321;
	queue<pair<int, int>> q;
	q.push(make_pair(start_y, start_x));
	v.clear();

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (cache[ny][nx] !=0 ||  A[ny][nx] > shark.size) continue;

			cache[ny][nx] = cache[y][x] + 1;
			if (A[ny][nx] > 0 && A[ny][nx] < shark.size) {
				if (min_eat >= cache[ny][nx]) {
					min_eat = cache[ny][nx];
					v.push_back(make_pair(make_pair(min_eat, ny), nx));
				}
			}
			q.push(make_pair(ny, nx));
		}
	}
}

void solution() {
	while (1) {
		bfs(shark.y, shark.x);

		if (v.empty()) break;

		sort(v.begin(), v.end());
		A[v[0].first.second][v[0].second] = 0;
		shark.y = v[0].first.second;
		shark.x = v[0].second;
		shark.eat++;
		if (shark.eat == shark.size) {
			shark.size++;
			shark.eat = 0;
		}

		res += v[0].first.first;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 9) {
				A[i][j] = 0;
				shark.y = i;
				shark.x = j;
				shark.eat = 0;
				shark.size = 2;
			}
		}

	solution();

	cout << res << "\n";

	return 0;
}
