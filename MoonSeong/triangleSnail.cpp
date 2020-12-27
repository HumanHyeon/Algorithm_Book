#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int snail[n][n];
    int dx = 0, dy = 1; // (0, 1) = 아래 -> (1, 0) = 우 -> (-1, -1) = 좌상 -> (반복)
    
    //init all 0
    for (int i = 0; i < n*n; i++)
        snail[i / n][i % n] = 0;
    //init: blank == -1
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            snail[i][j] = -1;
    
    int x = 0, y = 0;
    //x,y = 현재위치, x+dx, y+dy = 다음위치
    int content = 1;
    while (true) {
        //전 반복주기에서 계산한 칸 x,y 가 비어있지 않다면 종료
        if (snail[y][x] != 0) 
            break;
        
        snail[y][x] = content++;
        // 다음칸이 배열의 범위 밖이거나, 다음칸이 빈칸이 아니면 방향전환
        if ((x + dx >= n || y + dy >= n) || snail[y+dy][x+dx] != 0)
            switch(dx) {
                case -1: dx = 0; dy = 1; break;
                case 0:  dx = 1; dy = 0; break;
                case 1:  dx = -1; dy = -1; break;
            }
        //다음 (x,y) 지정
        x += dx;
        y += dy;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (snail[i][j] != -1) answer.push_back(snail[i][j]);
    
    return answer;
}
