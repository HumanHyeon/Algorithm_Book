#include <iostream>
using namespace std;

#define BOARD_SIZE 6
#define RANGE (BOARD_SIZE <= x || BOARD_SIZE <= y || x < 0 || y < 0)

int board[BOARD_SIZE][BOARD_SIZE] = {
   {1, 0, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 0},
   {1, 1, 1, 1, 0, 0},
   {1, 0, 0, 0, 0, 1},
   {1, 1, 1, 1 ,1 ,1}
};

int startY = 0, startX = 0;
int finishY = 0, finishX = 4;

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };   //Up Down Left Right

int findRoad(int y, int x, int preY = -1, int preX = -1) {
    if (RANGE)    return 0;
    if (y == finishY && x == finishX) {
        cout << "find" << endl;
        return 99;
    }
    if (board[y][x] == 0) return 0;

    /*cout << y << ", " << x << endl;*/
    for (int direction = 0; direction < 4; direction++) {
        int nextX = x + dx[direction], nextY = y + dy[direction];
        if (nextY == preY && nextX == preX)   continue;
        /*cout << "\t\t" << nextY << ", " << nextX << endl;*/
        if (nextY == finishY && nextX == finishX)   cout << "find2" << endl;    //edit this part
        findRoad(nextY, nextX, y, x);   //edit this part
    }
    //anything working
}

int main() {
    cout << findRoad(startY, startX) << endl;
}
