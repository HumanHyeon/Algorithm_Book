#include <iostream>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

//보드의 세로 크기는 N, 가로 크기는 M

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<string> board(n);
    for (int i = 0; i < n; i++)
        scanf("%s", &board[i]);

    vector<int> red(2), blue(2), o(2);
    int answer = -1;

    
    int flag = 0;
    for (int i = 0; i < n*m; i++) {
        if (flag == 3)
            break;
        char ch = board[i/n][i%n];
        if (ch == 'R') {
            red[0] = i/n;
            red[1] = i%n;
            flag++;
        }
        if (ch == 'B') {
            blue[0] = i/n;
            blue[1] = i%n;
            flag++;
        }
        if (ch == 'O') {
            o[0] = i/n;
            o[1] = i%n;
            flag++;
        }
    }

    answer = breakthrogh(board, red, blue, o);
    cout << answer;

    return 0;
}

int breakthrogh(vector<string>& board, vector<int> red, vector<int> blue, vector<int> o) {

    return 0;
}

void move(int dir, vector<string>& board, vector<int> red, vector<int> blue, vector<int> o) {
    //dir = 2, 4, 6, 8
    vector<int> direction(2);
    switch(dir) {
        case 2:
        case 8:
            direction[0] = (5-dir)/3;
            direction[1] = 0;
            break;
        case 4:
        case 6:
            direction[0] = 0;
            direction[1] = dir-5;
            break;
    }
    
    while (true) {  //here~
        bool canMoveRed;
        bool canMoveBlue;
        red[0] += direction[0];
        red[1] += direction[1];
        blue[0] += direction[0];
        blue[1] += direction[1];
        
        if (board[red[0]][red[1]] != '.')
            canMoveRed = true;
        if (board[blue[0]][blue[1]] != '.')
            canMoveRed = true;
        

        if (!canMoveRed && !canMoveBlue)
            break;
        if (canMoveRed) {
            
        }
        if (canMoveBlue) {

        }
    }
}
