#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];
int restore(int last, int used) {
    // 기저 사례
    if (used == (1 << k) - 1) return 0;
    // 메모이제이션
    int& ret = cache[last][used];
    if (ret != -1) return ret;
    ret = 0;
    for(int next = 0;next < k;++next)
        if ((used & (1 << next)) == 0) {
            int cand = overlap[last][next] + restore(next, used + (1 << next));
            ret = max(ret, cand);
        }
    return ret;
}

// 처음 호출시 last는 recover()가 최댓값을 반환한 시작 단어로,
// used는 1 << last로 둠
string reconstruct(int last, int used) {
    // 기저 사례
    if (used == (1 << k) - 1)return "";
    // 다음에 올 문자열 조각을 찾음
    for (int next = 0; next < k; ++next) {
        // next를 사용했을 경우의 답이 최적해와 같다면 next를 사용
        int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
        if (restore(last, used) == ifUsed)
            return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
    }
    //뭔가 잘못된 경우
    return "****oops****";
}

int main() {


    return 0;
}
