#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] = {0, };
    int x = 0, y = 0, state = 0, num = 1;
    
    for(int i = 0; i < n; i++)
    {
        switch(state)
        {
            case 0:
                for(int j = i; j < n; j++)
                    arr[x++][y] = num++;
                x--;
                y++;
                state = 1;
                break;
            case 1:
                for(int j = i; j < n; j++)
                    arr[x][y++] = num++;
                x--;
                y -= 2;
                state = 2;
                break;
            case 2:
                for(int j = i; j < n; j++)
                    arr[x--][y--] = num++;
                x += 2;
                y++;
                state = 0;
                break;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}
