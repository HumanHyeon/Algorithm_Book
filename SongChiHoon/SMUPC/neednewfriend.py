import sys
input = sys.stdin.readline
sys.setrecursionlimit(1234568)
H, W = map(int, input().split())
a, b = -1, -1
g = []

for i in range(H):
    t = list(input())
    if 'I' in t:
        a, b = i, t.index('I')
    g.append(t)
 
v = [[0] * W for i in range(H)]
 
dy = 1, -1, 0, 0
dx = 0, 0, 1, -1
cnt = 0

def dfs(y, x):
    global cnt
    v[y][x] = 1
    
    for i in range(4):
      
        ty, tx = y + dy[i], x + dx[i]
        
        if not (0 <= ty < H and 0 <= tx < W):
            continue
        if v[ty][tx]:
            continue
        if g[ty][tx] == 'X':
            continue
        if g[ty][tx] == 'P':
            cnt += 1
        dfs(ty, tx)
 
dfs(a, b)
print(cnt if cnt else "TT")
