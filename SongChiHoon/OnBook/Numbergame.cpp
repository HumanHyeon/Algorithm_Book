const int EMPTY = -987654321;
int n, board[50];
int cache[50][50];
int play(int left, int right) {
    if(left > right) return 0;
    int &ret = cache[left][right];
    if(ret != EMPTY) return ret;

    ret = max(board[left] - play(left + 1, right), board[right] - play(left,right -1));

    if(right - left + 1 >= 2) {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right -2));
    }
}