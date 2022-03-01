#include <string>
#include <vector>

using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int m=0;

void dfs(vector<vector<int>>& board, int cost, int y, int x, int di) {
    if(y==board.size()-1 && x==board[0].size()-1){
        m = cost;
        return;
    }
        
    int fy,fx;
    int tmpCost;

    for(int i=0;i<4;++i) {
        fy = y+dy[i];
        fx = x+dx[i;]
        tmpCost = cost;
        
        if(board[fy][fx]==1) continue;
        if(fy==board.size() || fx==board[0].size()) continue;
        if(fy==-1 || fx==-1) continue;
            
        board[fy][fx] = 1;
        
        if(x==0 && y==0) cost += 100;
        else{
            if(di==i) cost += 100;
            else cost += 500;
        }
        dfs(board, cost, fy, fx, i);
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    dfs(board,answer,0,0,0);
    answer = m;
    
    return answer;
}
