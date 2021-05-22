#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMax(vector<int> v, int y){
    int x = 0;
    for(int i = 0; i < 4; i++)
        if(i != y)
            x = max(x, v[i]);
    return x;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            land[i][j] += findMax(land[i - 1], j);
            answer = max(answer, land[i][j]);
        }
    }
    return answer;
}
