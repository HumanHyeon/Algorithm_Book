#include <iostream>
#define SIZE 7
using namespace std;

int n = SIZE, board[SIZE][SIZE] = {
	{2, 5, 1, 6, 1, 4, 1},
	{6, 1, 1, 2, 2, 9, 3},
	{7, 2, 3, 2, 1, 3, 1},
	{1, 1, 3, 1, 7, 1, 2},
	{4, 1, 2, 3, 4, 1, 2},
	{3, 3, 1, 2, 3, 4, 1},
	{1, 5, 2, 9, 4, 7, -100}
};
int cache[SIZE][SIZE];

int jump(int y, int x) {
	if (y >= n || x >= n)	return 0;
	if (y == n - 1 && x == n - 1)	return 1;

	int& ret = cache[y][x];
	if (ret != -1)	return ret;
	int jumpSize = board[y][x];
	return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main() {
	memset(cache, -1, sizeof(cache));
	cout << jump(0, 0) << endl;
}
