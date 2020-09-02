#include <iostream>
#include <algorithm>
using namespace std;

const int EMPTY = -987654321;
int n, board[50];
int cache[50][50];
int play(int left, int right) {
    // 기저 사례 : 모든 수가 다 없어졌을 때
    if (left > right)return 0;
    int& ret = cache[left][right];
    if (ret != EMPTY)return ret;
    // 수를 가져가는 경우
    ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
    // 수를 없애는 경우
    if (right - left + 1 >= 2) {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
    }
    return ret;
}

int main() {
    int C;

    cin >> C;
    for (int i = 0; i < C; ++i) {
        for (int a = 0; a < 50; ++a)
            for (int b = 0; b < 50; ++b)
                cache[a][b] = EMPTY;
        cin >> n;
        for(int j=0;j<n;++j)
            cin >> board[j];
        cout << play(0, n - 1) << endl;
    }

    return 0;
}
