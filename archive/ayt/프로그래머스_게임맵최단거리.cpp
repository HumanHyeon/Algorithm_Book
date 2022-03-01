#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const vector<int> dy = { -1,1,0,0 };
const vector<int> dx = { 0,0,-1,1 };

bool visit[101][101];

int solution(vector<vector<int>> maps) {
	queue<pair<int, int>> q;
	int n = maps.size() - 1;
	int m = maps[0].size() - 1;

	visit[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || ny > n || 0 > nx || nx > m) continue;
			if (maps[ny][nx] == 0) continue;

			if (!visit[ny][nx]) {
				visit[ny][nx] = true;
				maps[ny][nx] = maps[y][x] + 1;
				q.push(make_pair(ny, nx));
			}

		}
	}

	return maps[n][m] == 1 ? -1 : maps[n][m];
}
int main() {
	vector<vector<int> > maps = {
		{1,0,1,1,1},
		{1,0,1,0,1},
		{1,0,1,1,1},
		{1,1,1,0,1},
		{0,0,0,0,1} };

	cout << solution(maps);

	return 0;
}
