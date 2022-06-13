#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, res = 0;
int n[21];
int tmp[21];

void combination(int index, int depth,int r) {
    if (depth == r) {
        int sum = 0;
        for (auto elem : tmp) {
            sum += elem;
        }
        if (sum == S) res++;

        return;
    }

    for (int i = index; i < N; i++) {
        tmp[depth] = n[i];
        combination(i + 1, depth + 1, r);
    }
}

void solution() {
    for (int i = 1; i <= N; i++)
        combination(0, 0, i);
    cout << res;
}

int main(){
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    solution();

    return 0;
}
