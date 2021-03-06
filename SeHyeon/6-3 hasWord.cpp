#include <iostream>
using namespace std;
#define BOARD_SIZE 5
#define RANGE BOARD_SIZE < x || y > BOARD_SIZE || x < 0 || y < 0

char board[BOARD_SIZE][BOARD_SIZE] = {
		{'U', 'R', 'L', 'P', 'M'},  //L
		{'X', 'P', 'R', 'X', 'T'},	//R
		{'G', 'I', 'A', 'E', 'T'},	//G I
		{'X', 'T', 'N', 'Z', 'Y'},
		{'X', 'O', 'Q', 'R', 'S'}
};		//GIRL찾기

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

bool hasWord(int y, int x, string word) {
	if (RANGE) {
		//cout << "\t" << x << " " << y << "\t범위 나감" << endl;
		return false;	//범위
	}
	if (board[y][x] != word[0]) {
		//cout << "\t" << "찾는 글자 : " << word[0] << " " << "검색한 글자 : " << board[y][x] << "\t" << x << " " << y << "\t첫 글자 없음" << endl;
		return false;	//첫글자
	}
	if (word.size() == 1)	return true;	//글자가 하나면 참

	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1)))
			return true;
	}
	return false;
}

int main()
{
	string findStr = "GIRL";
	bool isTrue;

	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			isTrue = hasWord(x, y, findStr);
			//cout << x << " " << y << " : " << findStr << " is " << isTrue << endl;
			if (isTrue) break;
		}
		if (isTrue) break;
	}


	cout << findStr << " is " << isTrue;
}
