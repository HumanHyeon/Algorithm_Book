def solution(board):
    n = len(board)
    from collections import deque
    dx = [-1, 0, 1, 0]
    dy = [0, -1, 0, 1]
    queue = deque()
    answer = float('inf')
    queue.append((0, 0, -1, 0))
    visit = {(0, 0, 0): 0, (0, 0, 1): 0, (0, 0, 2): 0, (0, 0, 3): 0}
    while queue:
        x, y, dir1, cost = queue.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            if -1 < nx < n and -1 < ny < n and not board[nx][ny]:
                newcost = cost
                if dir1 == -1:
                    newcost += 100
                elif (dir1 - d) % 2 == 0:
                    newcost += 100
                else:
                    newcost += 600
                if nx == n - 1 and ny == n - 1:
                    answer = min(answer, newcost)
                elif visit.get((nx, ny, d)) is None or visit.get((nx, ny, d)) > newcost:
                    visit[(nx, ny, d)] = newcost
                    queue.append((nx, ny, d, newcost))
    return answer
