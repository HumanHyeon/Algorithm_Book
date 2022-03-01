#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> table, vector<int> xy) {
    int sum = 0;
    int dx = xy[2] - xy[0] + 1;
    int dy = xy[3] - xy[1] + 1;

    for (int i = xy[1] - 1; i < xy[3]; i++) {
        sum += table[xy[0] - 1][i];
    }

    int tmp = 0;
    for (int i = 1; i < dx; i++)
        tmp += i*dy;
    sum = sum * dx + tmp;

    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N, vector<int>(N));
    vector<vector<int>> xy(M, vector<int>(4));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> xy[i][j];
        }
    }

    for (auto elem : xy)
        cout << solution(table, elem) << endl;
}
