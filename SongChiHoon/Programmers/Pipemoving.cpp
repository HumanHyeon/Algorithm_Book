// N*N 사이즈의 집이 있다. 이곳의 (0,0), (0,1) 좌표에 파이프가 놓여있다.

// 파이프의 이동 가능 방법

// 파이프는 항상 우측 하단을 향해 내려가야 한다.

// 가로 : 가로, 45도 대각선.

// 세로 : 세로, 45도 대각선.

// 대각선 : 가로, 세로, 45도 대각선.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pipe
{
    int pipe[2] = {1, 1};
};

int main()
{
    int housesize;
    cin >> housesize;

    int **house = new int*[housesize];

    for (int i = 0; i < housesize; i++)
        house[i] = new int [housesize];

    for (int i = 0; i < housesize; i++)
    {
        for (int j = 0; j < housesize; j++)
        {
            cin >> house[i][j];
        }
        
    }
    


}
