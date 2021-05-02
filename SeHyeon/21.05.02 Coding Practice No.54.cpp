#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>>& board) {
    for (auto fetch : board) {
        for (auto element : fetch)
            cout << element << " ";
        putchar('\n');
    }
}

void initBoard(const int rows, const int columns, vector<vector<int>>& board) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            board[i][j] = (i * columns + j + 1);
}

//void swap(int& a, int& b) {
//    int tmp;
//    
//    tmp = a;
//    a = b;
//    b = a;
//}

int runCycle(const int rows, const int columns, vector<vector<int>>& board, vector<int>& coordinate) {
    int x1 = coordinate[0] - 1, x2 = coordinate[2] - 1;
    int y1 = coordinate[1] - 1, y2 = coordinate[3] - 1;
    int min = -1;
    int flag = 0, beforeValue, nowValue;

    while (flag != 4) {
        if (flag == 0) {
            int tmpx = x2, tmpy = y1;

            beforeValue = board[tmpy][tmpx];
            while (tmpx != x1) {
                board[tmpy][tmpx] = board[tmpy][tmpx - 1];
                tmpx--;
            }
        }
        else if (flag == 1) {
            int tmpx = x2, tmpy = y2;

            nowValue = board[tmpy][tmpx];
            while (tmpy != y1 + 1) {
                board[tmpy][tmpx] = board[tmpy - 1][tmpx];
                tmpy--;
            }
            board[tmpy][tmpx] = beforeValue;
            beforeValue = nowValue;
        }
        else if (flag == 2) {
            int tmpx = x1, tmpy = y2;

            nowValue = board[tmpy][tmpx];
            while (tmpx != x2 - 1) {
                board[tmpy][tmpx] = board[tmpy][tmpx + 1];
                tmpx++;
            }
            board[tmpy][tmpx] = beforeValue;
            beforeValue = nowValue;
        }
        else if (flag == 3) {
            int tmpx = x1, tmpy = y1;

            while (tmpy != y2 - 1) {
                board[tmpy][tmpx] = board[tmpy + 1][tmpx];
                tmpy++;
            }
            board[tmpy][tmpx] = beforeValue;
        }
        flag++;
    }
    return 0;
}

//bool promising(vector<int>& coordinate) {
//    int x1 = coordinate[0], x2 = coordinate[2];
//    int y1 = coordinate[1], y2 = coordinate[3];
//    int tmp;
//
//    if (x2 == x1 && y2 == y1)
//        return false;
//    x1 > x2 ? tmp = x2, x2 = x1, x1 = tmp : x2;
//    y1 > y2 ? tmp = y2, y2 = y1, y1 = tmp : y2;
//    coordinate = { x1, y1, x2, y2 };
//    return true;
//}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int> (columns));
    
    initBoard(rows, columns, board);
    //printBoard(board);
    for (auto fetch : queries) {
        if (!(fetch[0] == fetch[2] && fetch[1] == fetch[3])) {
            runCycle(rows, columns, board, fetch);
            printBoard(board);
        }
        else
            answer.emplace_back(board[fetch[0]][fetch[1]]);
    }

    return answer;
}

int main()
{
    int rows = 5;
    int colums = 5;
    vector<vector<int>> queries = {
        { 2, 2, 5, 4 },
        { 3, 3, 6, 6 },
        { 5, 1, 6, 3 }
    };
    solution(rows, colums, queries);
}
