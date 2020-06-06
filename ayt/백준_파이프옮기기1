#include <iostream>
#include <vector>
using namespace std;

int n, home[17][17],result = 0;
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
vector<int> action[3] = { {0,2},{1,2},{0,1,2} };

void movePipe(int x,int y,int type) {
	for (int& elem : action[type]) {
		int tx = x + dx[elem];
		int ty = y + dy[elem];

		if (tx<1 || ty<1 || tx>n || ty>n || home[tx][ty])
			continue;

		if (elem == 2 && (home[tx - 1][ty] || home[tx][ty - 1]))
			continue;

		if (tx == n && ty == n) {
			++result;
			continue;
		}

		movePipe(tx, ty, elem);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> home[i][j];
		}
	}

	movePipe(1, 2, 0);
	cout << result << endl;

	return 0;
}
