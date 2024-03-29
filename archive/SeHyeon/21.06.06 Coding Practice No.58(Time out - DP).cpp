https://programmers.co.kr/learn/courses/30/lessons/12980

#include <iostream>
using namespace std;

bool powerOfTwo(int n) {
    int i;

    i = 1;
    while (i <= n) {
        if (i == n)
            return (true);
        i *= 2;
    }
    return (false);
}

int solution(int n) {
    int* dp;
    int i;

    dp = (int*)malloc(sizeof(int) * (n + 1));
    i = 0;
    while (i <= n) {
        if (powerOfTwo(i))
            dp[i] = 1;
        else {
            if (i % 2 == 0)
                dp[i] = dp[i / 2];
            else
                dp[i] = dp[i - 1] + 1;
        }
        i++;
    }

    return (dp[n]);
}
