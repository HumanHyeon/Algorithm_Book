#include<vector>
using namespace std;

int maxSize;

void extend(const vector<vector<int>>& board, int parax, int paray) {
    int extendLength;

    for (int y = paray; y < paray + maxSize - 1; y++) 
        for (int x = parax; x < parax + maxSize - 1; x++)
            if (board[y][x] == 0)   return;
    for (extendLength = 0; ; extendLength++) {
        bool exist = false;
        for (int i = 0; i < maxSize + extendLength; i++){
            if (board[0].size() <= parax + maxSize + extendLength || board.size() <= paray + maxSize + extendLength) {
                exist = true;
                break;
            }
            if (board[paray + maxSize + extendLength][parax + i] == 0 || board[paray + i][parax + maxSize + extendLength] == 0) {
                exist = true;
                break;
            }
        }
        if (exist) break;
    }

    maxSize = maxSize + extendLength;
}

int solution(vector<vector<int>> board){
    maxSize = 1;

    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board[0].size(); x++) {
            if (board[y][x] == 0)    continue;
            if (x + maxSize >= board[0].size())  continue;
            if (y + maxSize >= board.size())    continue;
            extend(board, x, y);
        }
    }

    return maxSize * maxSize;
}
