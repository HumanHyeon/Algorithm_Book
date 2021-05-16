#include <string>
#include <vector>

using namespace std;

int nqueens(vector<vector<int>>& board, int x, int y) {
    if (promising()) {    //set queen
        if ()
    }
    else {
        
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<int>> board;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(0);
        board.push_back(temp);
    }
    
    answer = nqueens(board, 0, 0);
    
    return answer;
}
