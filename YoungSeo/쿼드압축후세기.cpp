#include <string>
#include <vector>
 
using namespace std;
 
vector<vector<int>> MAP;
 
void Sol(int x, int y, int length, vector<int> &answer)
{
    bool zero,one;
    zero = true;
    one = true;
    for (int i = x; i < x + length; i++)
    {
        for (int j = y; j < y + length; j++)
        {
            if (MAP[i][j] == 0) one = false;
            if (MAP[i][j] == 1) zero = false;
        }}
 
    if (zero == true) {
        answer[0]++;
        return;
    }
    
    if (one == true) {
        answer[1]++;
        return;
    }
 
    Sol(x, y, length/ 2, answer);
    Sol(x, y + length / 2, length / 2, answer);
    Sol(x + length / 2, y, length / 2, answer);
    Sol(x + length / 2, y + length / 2, length / 2, answer);
}
 
vector<int> solution(vector<vector<int>> arr) 
{
    vector<int> answer = {0,0};
    
    MAP = arr;
    Sol(0, 0, arr.size(), answer);
    return answer;
}

