N, M = map(int, input().split())

before = [list(map(int, input().split())) for _ in range(N)]
after = [list(map(int, input().split())) for _ in range(N)]

if before == after:  # 변화가 없는 경우
    print('YES')

else:  
    for i in range(N):
        for j in range(M):
            if before[i][j] - after[i][j] != 0:
                x, y = i, j
                break
        if before[i][j] - after[i][j] != 0:
            break
    before_num = before[x][y] 
    after_num = after[x][y]

    lst = []
    i, j = x, y     # 가장 상단의 변화한 숫자의 좌표 

    while True:
        before[i][j] = after_num

        if i>0:     # 같은 값을 가진 인접 좌표를 저장
            if before[i-1][j] == before_num:
                lst.append((i-1,j))
        if j>0:
            if before[i][j-1] == before_num:
                lst.append((i,j-1))
        if i<N-1:
            if before[i+1][j] == before_num:
                lst.append((i+1,j))
        if j<M-1:
            if before[i][j+1] == before_num:
                lst.append((i,j+1))

        if not lst: # 모든 좌표를 사용한경우 
            break   
        i,j = lst.pop() # 저장된 좌표를 꺼내옴

    if before == after: # 모든 격자의 변화와 인접격자의 변화가 일치하는 경우 
        print('YES')
    else:
        print('NO')