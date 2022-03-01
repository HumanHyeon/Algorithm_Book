#include <iostream>
#include <vector>
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2
#pragma warning(disable : 4018)
using namespace std;

int result;

const int pipeType[2][2][2] = {
	{{0, 0}, {0, 1}},
	{{0, 0}, {1, 0}}
};
const int pipeType2[1][4][2] = {
	{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }
};

bool set(vector<vector<int>>& board, int& y, int& x, int type)
{
	bool ok = true;
	int ny, nx;

	switch (type)
	{
	case HORIZONTAL:
		for (int i = 0; i < 2; i++) {
			ny = y + pipeType[HORIZONTAL][i][0];
			nx = x + pipeType[HORIZONTAL][i][1];

			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
				ok = false;
				break;
			}
			else if (board[ny][nx])	ok = false;
		}
		if (ok) {
			x = nx;  y = ny;
		}
		break;
	case VERTICAL:
		for (int i = 0; i < 2; i++) {
			ny = y + pipeType[VERTICAL][i][0];
			nx = x + pipeType[VERTICAL][i][1];

			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
				ok = false;
				break;
			}
			else if (board[ny][nx])	ok = false;
		}
		if (ok) {
			x = nx;  y = ny;
		}
		break;
	case DIAGONAL:
		for (int i = 0; i < 4; i++) {
			ny = y + pipeType2[DIAGONAL - 2][i][0];
			nx = x + pipeType2[DIAGONAL - 2][i][1];

			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
				ok = false;
				break;
			}
			else if (board[ny][nx])	ok = false;
		}
		if (ok) {
			x = nx;  y = ny;
		}
		break;
	default:
		cout << "switch error" << endl;
		break;
	}
	return ok;
}
void routes(vector<vector<int>>& home, int type = HORIZONTAL, int y = 0, int x = 0) {
	if (!set(home, y, x, type))	return;
	if (y == home.size() - 1 && x == home.size() - 1) {
		result += 1;
		return;
	}
	switch (type)
	{
	case HORIZONTAL:
		routes(home, HORIZONTAL, y, x);
		routes(home, DIAGONAL, y, x);
		break;
	case VERTICAL:
		routes(home, VERTICAL, y, x);
		routes(home, DIAGONAL, y, x);
		break;
	case DIAGONAL:
		routes(home, HORIZONTAL, y, x);
		routes(home, VERTICAL, y, x);
		routes(home, DIAGONAL, y, x);
		break;
	default:
		break;
	}
}

int main() {
	int homeSize;	cin >> homeSize;

	vector<vector<int>> home;
	for (int i = 0; i < homeSize; i++) {
		vector <int> tmp;
		int input;
		for (int j = 0; j < homeSize; j++) {
			cin >> input;
			tmp.push_back(input);
		}
		home.push_back(tmp);
	}

	routes(home);
	cout << result << endl;
}
