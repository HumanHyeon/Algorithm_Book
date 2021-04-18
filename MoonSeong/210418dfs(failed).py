def dfs(x, computers, remainder):
    contained = []
    for i in range(len(computers[x])):
        if computers[x][i] == 1 and computers[x][i] in remainder:
            contained.append(i)
    for _ in contained:
        remainder.remove(_)
    for c in contained:
        dfs(c, computers, remainder)
    
def solution(n, computers):
    answer = 0

    remainder = []
    for i in range(n):
        remainder.append(i)

    while len(remainder) != 0:
        dfs(remainder[0], computers, remainder)
        answer += 1
    
    print(answer)

    return answer

solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]])
