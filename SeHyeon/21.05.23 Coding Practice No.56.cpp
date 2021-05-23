#include <string>
#include <vector>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

int answer;

typedef struct {
    int x;
    int y;
} position;

bool is_promising(vector<vector<int> >& path, position pos, int cost) {
    if (cost >= answer)
        return false;
    if (pos.x < 0 || pos.x >= path[0].size() || pos.y < 0 || pos.y >= path.size())
        return false;
    if (path[pos.y][pos.x] == 1)
        return false;
}

int calc_cost(int beforePostion, int flag, int cost) {
    if (beforePostion == UP)
        if (flag == DOWN)
            return cost + 100;
    else if (beforePostion == DOWN)
        if (flag == UP)
            return cost + 100;
    else if (beforePostion == LEFT)
        if (flag == RIGHT)
            return cost + 100;
    else if (beforePostion == RIGHT)
        if (flag == LEFT)
            return cost + 100;
    return cost + 500;
}

void dfs(vector<vector<int> > path, int beforePostion, position nowPos, int cost) {
    if (nowPos.x == path[0].size() - 1 && nowPos.y == path.size() - 1) {
        if (answer > cost)
            answer = cost;
        return;
    }
    path[nowPos.y][nowPos.y] = 1;
    for (int flag = 0; flag < 4; flag++) {
        position nextPos = nowPos;
        if (flag == beforePostion)
            continue;
        if (flag == UP) {
            nextPos.y--;
            if (is_promising(path, nextPos, calc_cost(beforePostion, flag, cost))) {
                dfs(path, UP, nextPos, calc_cost(beforePostion, flag, cost));
            }
        }
        else if (flag == DOWN) {
            nextPos.y++;
            if (is_promising(path, nextPos, calc_cost(beforePostion, flag, cost))) {
                dfs(path, DOWN, nextPos, calc_cost(beforePostion, flag, cost));
            }
        }
        else if (flag == LEFT) {
            nextPos.x--;
            if (is_promising(path, nextPos, calc_cost(beforePostion, flag, cost))) {
                dfs(path, LEFT, nextPos, calc_cost(beforePostion, flag, cost));
            }
        }
        else if (flag == RIGHT) {
            nextPos.x++;
            if (is_promising(path, nextPos, calc_cost(beforePostion, flag, cost))) {
                dfs(path, RIGHT, nextPos, calc_cost(beforePostion, flag, cost));
            }
        }
    }
}

int solution(vector<vector<int> > board) {
    answer = INT32_MAX;
    position pos;

    board[0][0] = 1;
    pos.x = 0;
    pos.y = 1;
    dfs(board, LEFT, pos, 100);
    pos.x = 1;
    pos.y = 0;
    dfs(board, UP, pos, 100);
    return answer;
}
