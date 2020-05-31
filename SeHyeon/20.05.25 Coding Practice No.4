#include <iostream>
#include <vector>
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2
#pragma warning(disable : 4018)
using namespace std;

const int pipeType[2][2][2] = {
	{{0, 0}, {0, 1}},
	{{0, 0}, {1, 0}}
};
const int pipeType2[1][4][2] = {
	{ {0, 0}, {0, 1}, {1, 0}, {1, 1} }
};

bool set(vector<vector<int>>& board, int &y, int &x, int type)
{
	bool ok = true;
	
	switch (type)
	{
	case HORIZONTAL:
		for (int i = 0; i < 2; i++) {
			const int ny = y + pipeType[HORIZONTAL][i][0];
			const int nx = x + pipeType[HORIZONTAL][i][1];
			
			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())	ok = false;
			else if (board[ny][nx])	ok = false;
			if (ok) {
				x = nx;  y = ny;
			}
		}
		break;
	case VERTICAL:
		for (int i = 0; i < 2; i++) {
			const int ny = y + pipeType[VERTICAL][i][0];
			const int nx = x + pipeType[VERTICAL][i][1];

			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())	ok = false;
			else if (board[ny][nx])	ok = false;
			if (ok) {
				x = nx;  y = ny;
			}
		}
		break;
	case DIAGONAL:
		for (int i = 0; i < 4; i++) {
			const int ny = y + pipeType2[DIAGONAL - 2][i][0];
			const int nx = x + pipeType2[DIAGONAL - 2][i][1];
		
			if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())	ok = false;
			else if (board[ny][nx])	ok = false;
			if (ok) {
				x = nx;  y = ny;
			}
		}
		break;
	default:
		cout << "switch error" << endl;
		break;
	}
	return ok;
}
int routes(vector<vector<int>>& home, int type = HORIZONTAL, int y = 0, int x = 0, int result = 0) {
	if (y == home.size() - 1 && x == home.size() - 1)	return ++result;
	if (!set(home, y, x, type))	return 0;
	
	for (int i = 0; i < 3; i++) {
		result += routes(home, i, y, x, result);
	}
	return result++;
}

int main() {
	int homeSize;	cin >> homeSize;
	/*int** home = new int* [homeSize];
	for (int i = 0; i < homeSize; i++) {
		home[i] = new int[homeSize];
		memset(home[i], 0, sizeof(int) * homeSize);
	}

	for (int i = 0; i < homeSize; i++) {
		for (int j = 0; j < homeSize; j++) {
			cin >> home[i][j];
		}
		cout << i << "번째 줄 입력 완료\n";
	}


	for (int i = 0; i < homeSize; i++)
		delete[] home[i];
	delete[] home;*/	
	
	vector<vector<int>> home;
	for (int i = 0; i < homeSize; i++) {
		vector <int> tmp;
		int input;
		for (int j = 0; j < homeSize; j++) {
			cin >> input;
			tmp.push_back(input);
		}
		home.push_back(tmp);
		cout << i + 1 << "번째 줄 입력 완료\n";
	}

	cout << routes(home);
}
