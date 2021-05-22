#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board){ 
    int answer = board[0][0]; 
    int row = board.size(); 
    int col = board[0].size(); 
    
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            
            if(board[i][j] == 1){ 
               
               //왼쪽,위,왼쪽위대각선 3개 비교해서 최소값 구한뒤 +1
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    
    return answer * answer;
}
