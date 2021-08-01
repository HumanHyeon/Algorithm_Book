import sys, copy

input = sys.stdin.readline

def move(dir):
    if dir == 0:
        for j in range(n):
            idx = 0
            for i in range(1, n):
                if a[i][j]:
                    temp = a[i][j]
                    a[i][j] = 0
                    if a[idx][j] == 0:
                        a[idx][j] = temp
                    elif a[idx][j] == temp:
                        a[idx][j] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        a[idx][j] = temp

    elif dir == 1:
        for j in range(n):
            idx = n-1
            for i in range(n - 2, -1, -1):
                if a[i][j]:
                    temp = a[i][j]
                    a[i][j] = 0
                    if a[idx][j] == 0:
                        a[idx][j] = temp
                    elif a[idx][j] == temp:
                        a[idx][j] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        a[idx][j] = temp

    elif dir == 2:
        for i in range(n):
            idx = 0
            for j in range(1, n):
                if a[i][j]:
                    temp = a[i][j]
                    a[i][j] = 0
                    if a[i][idx] == 0:
                        a[i][idx] = temp
                    elif a[i][idx] == temp:
                        a[i][idx] = temp * 2
                        idx += 1
                    else:
                        idx += 1
                        a[i][idx] = temp

    else:
        for i in range(n):
            idx = n-1
            for j in range(n - 2, -1, -1):
                if a[i][j]:
                    temp = a[i][j]
                    a[i][j] = 0
                    if a[i][idx] == 0:
                        a[i][idx] = temp
                    elif a[i][idx] == temp:
                        a[i][idx] = temp * 2
                        idx -= 1
                    else:
                        idx -= 1
                        a[i][idx] = temp


def dfs(cnt):
    global a, ans
    if cnt == 5:
        for i in range(n):
            for j in range(n):
                ans = max(ans, a[i][j])
        return

    temp_a = copy.deepcopy(a)
    for i in range(4):
        move(i)
        dfs(cnt + 1)
        a = copy.deepcopy(temp_a)


n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
ans = 0
dfs(0)
print(ans)