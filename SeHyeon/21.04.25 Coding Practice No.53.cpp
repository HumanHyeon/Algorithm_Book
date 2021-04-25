https://programmers.co.kr/learn/courses/30/lessons/12949

#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int arr1_row = arr1.size(), arr1_column = arr1[0].size();
    int arr2_row = arr2.size(), arr2_column = arr2[0].size();

    vector<vector<int>> answer(arr1_row, vector<int>(arr2_column));
    for (int i = 0; i < arr1_row; i++)
        for (int j = 0; j < arr2_column; j++) {
            int val = 0;
            for (int pos = 0; pos < arr1_column; pos++)
                val += (arr1[i][pos] * arr2[pos][j]);
            answer[i][j] = val;
        }
    return (answer);
}
