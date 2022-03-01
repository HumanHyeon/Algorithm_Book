#include <string>
#include <vector>

using namespace std;

void cntArr(vector<vector<int>>& arr, int y, int x, int s, vector<int>& answer) {
    bool tf = false;
    int sum = 0;

    for (int i = y; i < y + s; ++i) {
        for (int j = x; j < x + s; ++j) {
            if (arr[i][j] == 1) ++sum;
        }
    }
    if (sum == 0) ++answer[0];
    else if (sum == s * s) ++answer[1];
    else tf = true;

    if (tf) {
        cntArr(arr, y, x, s / 2, answer);                     //왼쪽 위
        cntArr(arr, y, x + s / 2, s / 2, answer);             //오른쪽 위
        cntArr(arr, y + s / 2, x, s / 2, answer);             //왼아래
        cntArr(arr, y + s / 2, x + s / 2, s / 2, answer);     //오아래
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0,0 };

    cntArr(arr, 0, 0, arr.size(), answer);

    return answer;
}
