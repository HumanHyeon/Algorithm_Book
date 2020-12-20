#include <vector>
using namespace std;

int number_of_area, max_size_of_one_area;
int size_of_one_area, color; 

void dfs(vector<vector<int>>& picture, int i, int j) {
    if (picture[i][j] == 0 || picture[i][j] == -1 || picture[i][j] != color)  return;
    size_of_one_area++;
    picture[i][j] = -1;
    if (j + 1 < picture[0].size()) dfs(picture, i, j + 1);  //우
    if (i + 1 < picture.size()) dfs(picture, i + 1, j);  //하
    if (j - 1 > -1) dfs(picture, i, j - 1); //좌
    if (i - 1 > -1) dfs(picture, i - 1, j); //상
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = max_size_of_one_area = 0;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) {
            color = picture[i][j];
            if (color == 0 || color == -1)  continue;
            size_of_one_area = 0;
            dfs(picture, i, j);
            number_of_area++;
            if (size_of_one_area > max_size_of_one_area)    max_size_of_one_area = size_of_one_area;
        }
    return { number_of_area, max_size_of_one_area };
}
