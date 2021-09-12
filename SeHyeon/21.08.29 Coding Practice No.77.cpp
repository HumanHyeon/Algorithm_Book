https://www.acmicpc.net/problem/22352

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int original[31][31];
int filming[31][31];

typedef struct {
	int x;
	int y;
	int o_value;
	int f_value;
}Pos;

Pos findDiffPart() {
	Pos pos;
	bool check = false;

	pos.x = -1;
	pos.y = -1;
	pos.o_value = -1;
	pos.f_value = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (original[i][j] != filming[i][j]) {
				pos.x = j;
				pos.y = i;
				pos.o_value = original[i][j];
				pos.f_value = filming[i][j];
				check = true;
				break;
			}
		}
		if (check)
			break;
	}
	return (pos);
}

bool promising(int x, int y) {
	return ((x >= 0 && x < m) && (y >= 0 && y < n));
}

void injectIntoTheOriginal(const Pos info,int x, int y) {
	static const int dx[] = { 0, 0, -1, 1 };
	static const int dy[] = { -1, 1, 0, 0 };
	
	for (int i = 0; i < 4; i++) {
		if (promising(x + dx[i], y + dy[i])) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (original[nextY][nextX] == info.o_value) {
				original[nextY][nextX] = info.f_value;
				injectIntoTheOriginal(info, nextX, nextY);
			}
		}
	}
}

bool solution(void) {
	Pos pos;

	pos = findDiffPart();
	if (pos.x == -1 && pos.y == -1)
		return (true);
	injectIntoTheOriginal(pos, pos.x, pos.y);
	pos = findDiffPart();
	if (pos.x == -1 && pos.y == -1)
		return (true);
	return (false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> original[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> filming[i][j];
	solution() ? cout << "YES" : cout << "NO";
}
