https://www.acmicpc.net/problem/11053

n = int(input())
nl = list(map(int, input().split()))

dp = [1 for _ in range(n)]
for i in range(1, n):
     std = nl[i]
     for j in range(i):
          cmp = nl[j]
          if std > cmp:
               dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))
