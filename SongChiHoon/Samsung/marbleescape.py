N, M = map(int, input().split())
B = [list(input().rstrip()) for _ in range(N)]
dx = [-1, 1, 0, 0]  
dy = [0, 0, -1, 1] 
queue = []  
visited = [[[[False] * M for _ in range(N)] for _ in range(M)] for _ in range(N)]

def pos_init():
    rx, ry, bx, by = 0, 0, 0, 0  
    for i in range(N):
        for j in range(M):
            if B[i][j] == 'R':
                rx, ry = i, j
            elif B[i][j] == 'B':
                bx, by = i, j
    queue.append((rx, ry, bx, by, 1))
    visited[rx][ry][bx][by] = True

def move(x, y, dx, dy):
    cnt = 0  
    while B[x+dx][y+dy] != '#' and B[x][y] != 'O':
        x += dx
        y += dy
        cnt += 1
    return x, y, cnt

def solve():
    pos_init()  
    while queue:  
        rx, ry, bx, by, depth = queue.pop(0)
        if depth > 10:  
            break
        for i in range(4):  
            nrx, nry, rcnt = move(rx, ry, dx[i], dy[i])  
            nbx, nby, bcnt = move(bx, by, dx[i], dy[i])  
            if B[nbx][nby] != 'O':  
                if B[nrx][nry] == 'O':  
                    print(depth)
                    return
                if nrx == nbx and nry == nby:  
                    if rcnt > bcnt:  
                        nrx -= dx[i]  
                        nry -= dy[i]
                    else:
                        nbx -= dx[i]
                        nby -= dy[i]
                if not visited[nrx][nry][nbx][nby]:
                    visited[nrx][nry][nbx][nby] = True
                    queue.append((nrx, nry, nbx, nby, depth+1))
    print(-1)  

solve()