// 간격(interval)로 이루어진 배열이 주어지면, 겹치는 간격 원소들을 합친 새로운
// 배열을 만드시오. 간격은 시작과 끝으로 이루어져 있으며 시작은 끝보다 
// 작거나 같습니다.

// Given a list of intervals, merge intersecting intervals.

// 예제)

// Input: {{2,4}, {1,5}, {7,9}}

// Output: {{1,5}, {7,9}}



// Input: {{3,6}, {1,3}, {2,4}}

// Output: {{1,6}}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, minval, maxval = 0;
    int minarr[3] = {};  int maxarr[3] = {};
    int input[2][3] = {};   int range[2][2] = {};

    cout << "Input : ";

    for(i = 0; i < 2; i++)
    {
        do
        {
            cin >> input[i][j];
            j++;
        } while (input[0][j] > input[1][j] && j < 3);
    }

    copy(input, input + 3, minarr);
    copy(input + 4, input + 7, maxarr);

    sort(minarr, minarr + 3);
    sort(maxarr, maxarr + 3);

    minval = minarr[0]; maxval = maxarr[2];

    if(minarr[1] < maxarr[0])
    {
        // 배열 2개 나옴
        range[0][0] = minarr[0];
        range[0][1] = maxarr[1];

        cout << "Output : {" <<
    }
    if(minarr[2] < maxarr[2])
    {
        // 배열 1개 나옴
        range[0][0] = minarr[0];
        range[0][1] = maxarr[2];

        cout << "Output : {" << 
    }

    return 0;
}