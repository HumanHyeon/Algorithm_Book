#include <string>
#include <vector>

using namespace std;

bool isErasable(int y, int x, vector<string>& board);
void erase(int m, int n, vector<string>& eraseBoard, vector<string>& board);
void drop(int m, int n, vector<string>& board);

void check(int m, int n, vector<string>& board) {
    vector<string> eraseBoard = board;  //t = earasable, f = non-erasable
    bool isChanged = false;
    
    //init
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            eraseBoard[y][x] = 'f';
    
    //check (m-1)*(n-1)
    for (int y = 0; y < m - 1; y++)
        for (int x = 0; x < n - 1; x++)
            if (isErasable(y, x, board)) {
                isChanged = true;
                eraseBoard[y][x] = 't';
                eraseBoard[y+1][x] = 't';
                eraseBoard[y][x+1] = 't';
                eraseBoard[y+1][x+1] = 't';
            }
    
    vector<string> tempBoard = board;
    erase(m, n, eraseBoard, board);
    drop(m, n, board);
    if (tempBoard == board) 
        return;
    else 
        check(m, n, board);
}

bool isErasable(int y, int x, vector<string>& board) {
    //check bottom, right, bottom-right
    if (board[y][x] != board[y+1][x+1])
        return false;
    if (board[y][x] != board[y+1][x])
        return false;
    if (board[y][x] != board[y][x+1])
        return false;
    return true;
}

void erase(int m, int n, vector<string>& eraseBoard, vector<string>& board) {
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (eraseBoard[y][x] == 't') 
                board[y][x] = '-';
}

void drop(int m, int n, vector<string>& board) {    //m = 세로, n = 가로
    string temp = "";
    for (int i = 0; i < m; i++)
        temp += "-";
    vector<string> boardRotated90(n, temp);
    
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            boardRotated90[y][m-x-1] = board[x][y];
    
    for (int y = 0; y < n; y++) {
        temp = "";
        for (int x = 0; x < m; x++)
            if (boardRotated90[y][x] == '-') 
                continue;
            else 
                temp += boardRotated90[y][x];
        for (int i = temp.length(); i < m; i++)
            temp += '-';
        
        for (int x = m - 1; x >= 0; x--) 
            board[x][y] = temp[m - 1 - x];
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    check(m, n, board);
    
    for (int y = 0; y < m; y++) 
        for (int x = 0; x < n; x++)
            if (board[y][x] == '-')
                answer++;
    
    return answer;
}
