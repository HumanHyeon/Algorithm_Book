https://www.acmicpc.net/problem/21735

N, M = map(int, input().split())
a_seq = list(map(int, input().split()))

def dfs(size, time, pos):
     print(time, " -- ", size);
     #기저사례
     if (time == 0):
          return;
     #1번 - 굴림
     if (pos + 1 < N):
          dfs(size + a_seq[pos], time - 1, pos + 1)
     #2번 - 던짐
     if (pos + 2 < N):
          dfs(int(size / 2) + a_seq[pos + 2], time - 1, pos + 2)

ans = 1
dfs(1, M, 0)
print(ans)

