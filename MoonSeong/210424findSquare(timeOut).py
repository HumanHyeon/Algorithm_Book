def isExpansable(board, level):
    next = False
    nextBoard = [[0 for x in range(len(board[0]) - 1)] for y in range(len(board) - 1)]

    for y in range(len(board) - 1):
        for x in range(len(board[0]) - 1):
            if board[y][x] == 1 and board[y+1][x] == 1 and board[y][x+1] == 1 and board[y+1][x+1] == 1:
                next = True
                nextBoard[y][x] = 1

    if next:
        return isExpansable(nextBoard, level + 1)
    else:
        return level*level
    
def solution(board):
    sum = 0
    for y in range(len(board)):
        for x in range(len(board[0])):
            sum += board[y][x]
    
    if sum == 0:
        answer = 0
    else:
        answer = isExpansable(board, 1)

    return answer
