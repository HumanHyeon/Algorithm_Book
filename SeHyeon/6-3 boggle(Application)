#include <iostream>
using namespace std;

#define BOARD_SIZE 4
#define RANGE BOARD_SIZE < x || y > BOARD_SIZE || x < 0 || y < 0

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
char board[30][BOARD_SIZE][BOARD_SIZE];

bool hasWord(int, int, int, string);
int scoreCalc(int);

int answer_score[30], answer_wordCount[30];
string answer_dic[30];

int main()
{
	//Input part
	int createWord;		cin >> createWord;
	string* dic = new string[createWord]();
	if (!dic)	exit(1);
	for (int i = 0; i < createWord; i++)	cin >> dic[i];

	int createBoard;	cin >> createBoard;
	for (int i = 0; i < createBoard; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			for (int k = 0; k < BOARD_SIZE; k++)
				cin >> board[i][j][k];
	
	//Working part
	for (int selectBoard = 0; selectBoard < createBoard; selectBoard++) {	//Acess board
		int wordCount = 0, longWordIndex = -1, score = 0;
		bool presence = false;
		for (int selectWord = 0; selectWord < createWord; selectWord++) {	//Search word at now board
			string findWord = dic[selectWord];
			
			bool isTrue;

			//Searching
			for (int x = 0; x < BOARD_SIZE; x++) {
				for (int y = 0; y < BOARD_SIZE; y++) {
					isTrue = hasWord(selectBoard, x, y, findWord);
					if (isTrue) {
						if (isTrue)	break;
					}
					if (isTrue)	break;
				}
				if (isTrue)	break;
			}
			if (isTrue) {

				//cout << dic[selectWord] << endl;
				score += scoreCalc(dic[selectWord].length());

				wordCount++;
				presence = true;

				if (longWordIndex == -1)	longWordIndex = selectWord;
				else {
					longWordIndex = dic[longWordIndex].length() < dic[selectWord].length() ? selectWord : longWordIndex;
					if (dic[longWordIndex].length() == dic[selectWord].length())
						longWordIndex = dic[longWordIndex].compare(dic[selectWord]) == 1 ? selectWord : longWordIndex;
				}
			}
		}
		if (presence)
		{
			answer_score[selectBoard] = score;
			answer_dic[selectBoard] = dic[longWordIndex];
			answer_wordCount[selectBoard] = wordCount;
		}
	}

	for (int output = 0; output < createBoard; output++)
		cout << answer_score[output] << " " << answer_dic[output] << " " << answer_wordCount[output] << endl;
}

bool hasWord(int nowBoard, int x, int y, string word) {
	if (RANGE)	return false;
	if (board[nowBoard][x][y] != word[0])	return false;
	if (word.size() == 1) return true;

	for (int direction = 0; direction < 8; direction++) {
		int nextX = x + dx[direction], nextY = y + dy[direction];
		if (hasWord(nowBoard, nextX, nextY, word.substr(1)))
			return true;
	}
	return false;
}

int scoreCalc(int wordLength) {
	int score;
	switch (wordLength) {
	case 0:
		score = 1000000;	//identify logic error
		break;
	case 1:
	case 2:
		score = 0;
		break;
	case 3:
	case 4:
		score = 1;
		break;
	case 5:
		score = 2;
		break;
	case 6:
		score = 3;
		break;
	case 7:
		score = 5;
		break;
	case 8:
		score = 11;
		break;
	default:
		score = -10000000;	//identify logic error
		break;
	}
	return score;
}
