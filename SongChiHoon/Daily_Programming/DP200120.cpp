// 간격(interval)로 이루어진 배열이 주어지면, 겹치는 간격 원소들을 합친 새로운 배열을 만드시오. 간격은 시작과 끝으로 이루어져 있으며 시작은 끝보다 작거나 같습니다.

// Given a list of intervals, merge intersecting intervals.

// 예제)

// Input: {{2,4}, {1,5}, {7,9}}

// Output: {{1,5}, {7,9}}



// Input: {{3,6}, {1,3}, {2,4}}

// Output: {{1,6}}

#include <iostream>
using namespace std;

int main()
{
    int input[3][2];

    cout << "Input : ";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> input[i][j];
        }
    }
    
    


    
    return 0;
}