def dfs(x, computers, remainder):
    contained = []
    for i in range(len(computers[x])):
        if computers[x][i] == 1 and i in remainder:
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
    #main routine
    while len(remainder) != 0:
        dfs(remainder[0], computers, remainder)
        answer += 1

    return answer
