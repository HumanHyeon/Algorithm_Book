#include <iostream>
#include <vector>
using namespace std;

const int coverType [4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
    };

int cover (vector<vector<int> >& board) 
    {
        int y = -1, x = -1;

        for (int i = 0; i <board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == 0) 
                {
                    y = i;
                    x = j;
                    break;
                }
            }
            if(y != -1) break;
        }
        if(y == -1)
            return 1;

        int ret = 0;

        for(int type = 0; type < 4; ++type)
        {
            if(set(board, y, x, type, 1))
                ret += cover(board);
            
            set(board, y, x, type, -1);            
        }

        return ret;

    };

bool set (vector<vector<int> >& board, int y, int x, int type, int delta)
    {
        bool ok = true; //판별기

        for (int i = 0; i < 3; ++i) 
        {
            const int ny = y + coverType[type][i][0];
            const int nx = x + coverType[type][i][1];
            if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
                ok = false;
            else if((board[ny][nx] += delta) > 1)
                ok = false;
        }

        return ok;
    };

int main() 
{
    int C, H, W;
    printf("케이스 갯수 입력 :");
    cin >> C;
    printf("행과 열의 갯수 입력 : ");
    cin >> H, W;

    for(int i; i < H; i++)
    {
        for(int j; j < W; j++)
        {
            if(rand()%2 == 1)
            {
                printf(".");
            }
            else
                printf("#");
        }
        printf("\n");
    }

    set(H, W);
    cover();

    return 0;
}
