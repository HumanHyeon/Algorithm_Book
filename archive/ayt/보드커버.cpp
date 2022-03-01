#include <iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
		{{0, 0}, {1, 0}, {0, 1}},
		{{0, 0}, {0, 1}, {1, 1}},
		{{0, 0}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {1, -1}}
};

bool set(vector<vector<int> >& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
};

int cover(vector<vector<int> >& board)
{
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1)
		return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
};

int main(void)
{
	int C;
	int H = 0, W = 0;
	int board[H][W];
	int result;

	cin >> C;
	for (int a = 0; a < C; a++) {
		cin >> H, W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (rand() % 2 == 0) {
					cout << "1";
					board[i][j] = 1;
				}
				else {
					cout << "0";
					board[i][j] = 0;
				}
			}
			cout << endl;
		}
	}
	cout << endl;
	for (int b = 0; b < C; b++) {
		result = cover(board);
		cout << result << endl;
	}
	
	return 0;
}
