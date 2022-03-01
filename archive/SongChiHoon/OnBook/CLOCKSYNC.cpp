#include <iostream>
#include <vector>
using namespace std;
#define SWITCH 10
#define CLOCK 16

int LINK[SWITCH][CLOCK] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

bool areAligned(LINK[int i][int j])
{
    for(i = 0; i < SWITCH; i++)
    {
        for(j = 0; j < CLOCK; j++)
        {
            if(LINK[i][j] = 0)
            {
                return false;
            }
        }
    }

    return true;
}


int Calculating(vector<int> &clocks, int swtch)
{
    for(int clock = 0; clock < CLOCK; clock++)
    {
        if (LinkSet[swtch][clock] == 1)
        {
            clocks[clock] += 3;
            if (clocks[clock] == 15)
            {
                clocks[clock] = 3
            }
        }
    }
}

int main()
{
    int Case, Time[16], Answer;

    printf("케이스 갯수를 입력하세요 : ");
    getc >> Case;

    for(int Cycle = 0; Cycle < Case; Cycle++)
    {
        printf("시간을 입력하십시오\n(12, 3, 6, 9 만 입력가능) : ");

        for(int i = 0; i < 16; i++)
        {
            getc >> Time[i];
        }
        Answer = Calculating(Time[]);

        printf("스위치 이용 횟수 : %d", Answer);

    }

    return 0;
}
