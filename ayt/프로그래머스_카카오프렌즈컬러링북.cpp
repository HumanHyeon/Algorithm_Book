#include <vector>

using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m1, n1;

int dfs(int location, int x, int y, vector<vector<int>> &picture) {
    int cnt = 1;

    if (x >= m1 || y >= n1 || x < 0 || y < 0 || picture[x][y] != location)
        return 0;
    else {
        picture[x][y] = 0;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            cnt += dfs(location, nx, ny, picture);
        }
    }

    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    m1 = m; n1 = n;

    for (int i = 0; i < picture.size(); ++i) {
        for (int j = 0; j < picture[i].size(); ++j) {
            if (picture[i][j]!=0){
                int size = dfs(picture[i][j],i, j, picture);
                max_size_of_one_area = (max_size_of_one_area < size) ? size : max_size_of_one_area;
                ++number_of_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}
