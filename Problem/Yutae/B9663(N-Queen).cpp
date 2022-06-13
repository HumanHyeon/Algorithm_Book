#include <iostream>
#include <algorithm>

using namespace std;

int N, res = 0;
int a[16];

bool check(int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (a[i] == a[cnt] || abs(a[cnt] - a[i]) == cnt - i)
            return false;
    }

    return true;
}

void nqueen(int cnt) {
    if (cnt == N) {
        res++;
        return;
    }

    for (int i = 0; i < N; i++) {
        a[cnt] = i;
        if (check(cnt))
            nqueen(cnt + 1);
    }
}

void solution() {
    nqueen(0);
    cout << res;
}

int main(){
    cin >> N;

    solution();

    return 0;
}
