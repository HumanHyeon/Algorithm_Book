#include <string>
#include <vector>

#include <iostream>
using namespace std;

//DP: 임의의 x,y 에서 목적지까지 드는 비용을 필요할때마다 계산

#define MAX_COST 100
//x, y에서 N-1, N-1까지의 최단거리 계산
int getCost(int x, int y, vector<vector<int>> cost) {   
    int size = cost.size();
    if (0 <= x && x < size && 0 <= y && y < size) { //범위안
        if (cost[y][x] != 0)    //구했던 값인경우
            return cost[y][x];
        else {                  //구하지않았던 값인 경우: 지금 계산
            
        }
    }
    else                                           //범위밖
        return 99999;
    return 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    
    int curX = 0;
    int curY = 0;
    
    vector<vector<int>> cost = board;   //board 사이즈로 복사
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cost[i][j] = 0;             //0으로 초기화
    
    while (curX != N-1 && curY != N-1) {
        //approach (N-1, N-1)
        int pool[4][2] = { {0, N-1}, {0, N+1}, {N-1, 0}, {N+1, 0} };
        //4방향 모두 비용계산
    }
    
    return answer;
}
