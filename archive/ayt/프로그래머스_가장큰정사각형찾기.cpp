#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    if(board.size()<2 || board[0].size()<2){
        return 1;
    }
    
    for(int i=1;i<board.size();++i)
        for(int j=1;j<board[0].size();++j)
            if(board[i][j]==1){
                board[i][j] = min({board[i-1][j-1], board[i-1][j] , board[i][j-1]})+1;
                answer = max(answer,board[i][j]);
            }

    return answer*answer;
}
