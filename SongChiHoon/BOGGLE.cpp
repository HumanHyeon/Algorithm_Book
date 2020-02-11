#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define boardsize 5
#define range boardsize < x || boardsize < y || x < 0 || y < 0

char Board[boardsize][boardsize];
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

//보드에서 주어진 단어의 시작점을 찾아서 반환하는 함수
bool hasWord(int y, int x, const string& word) {
    if (range == true) return false;
    if (Board[y][x] != word[0]) return false;
    if (word.size() == 1) return true;
    if (Board[y][x] == word[0]) return true;
    for (int direction = 0; direction < 8; ++direction)
    {
        int next_Y = y + dy[direction], next_X = x + dx[direction];
        if (hasWord(next_Y, next_X, word.substr(1)) == 1)
            return true;
    }
    return false;
}

int main() {
    //보드 생성하기
    char letter;
    for (int i = 0; i < boardsize; i++) 
    {
        for (int j = 0; j < boardsize; j++)
        {
            letter = 97 + rand() % 26;
            Board[i][j] = letter;
        }
    }

    //화면에 보드 보여주기
    for (int i = 0; i < boardsize; i++) {
        for (int j = 0; j < boardsize; j++)
        {
            cout << Board[i][j], cout << "  ";
        }
        cout << endl, cout << endl;
    }

    //입력받기
    cout << endl, cout << "찾고 싶은 단어를 입력하세요 : ";
    string findingword;    cin >> findingword;
    
    //판별하기
    for(y = 0; y < Board; y++)
    {
        for(x = 0; x < Board; x++)
        {
            if (hasWord(y, x, findingword) == true)
            {
                cout << "단어가 있습니다.";
            }
            else
            {
                cout << "단어가 없습니다.";
            }
            
        }
    }
    return 0;
}