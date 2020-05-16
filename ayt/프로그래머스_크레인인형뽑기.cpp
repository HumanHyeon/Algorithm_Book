#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int tmp;
    vector<int> basket;
    
    for(int i = 0 ; i < moves.size() ; i++) {
        for(int j = 0 ; j < board.size() ; j++) {
            if(board[j][moves[i]-1] != 0) {
                tmp = j;
                break;
            }
            else
                tmp = -1;
        }
        
        if(tmp != -1) {  
            basket.push_back(board[tmp][moves[i]-1]);
            board[tmp][moves[i]-1] = 0;                                               
        }
        
        if(basket[basket.size()-1] == basket[basket.size()-2]) {
            basket.pop_back();
            basket.pop_back();
            answer += 2;
        }
    }
    return answer;
}

// 0 0 0 0 0
// 0 0 1 0 3
// 0 2 5 0 1
// 4 2 4 4 2
// 3 5 1 3 1
