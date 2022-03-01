#define MOD 1234567
using namespace std;

long long cache[2000];

void dpCalc(long long n) {
    if (!cache[n]) {
        if (!cache[n - 2])  dpCalc(n - 2);
        if (!cache[n - 1])  dpCalc(n - 1);
        cache[n] = (cache[n - 2]  + cache[n - 1]) % MOD;
    }
}

long long solution(int n) {
    if (n == 1)  return 1;
    cache[0] = cache[1] = 1;
    dpCalc(n);

    return cache[n] % MOD;
}

/*  반복문 Ver
long long solution(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    return dp[n];
}
*/
