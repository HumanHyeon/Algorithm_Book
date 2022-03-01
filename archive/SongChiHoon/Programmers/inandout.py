from collections import deque

def solution(enter, leave):
    answer = [0 for _ in range(len(enter)+1)]
    leave = deque(leave)
    
    room = []
    for i in enter:
        for r in room:
            answer[r] += 1
        answer[i] += len(room)
        room.append(i)

        while leave and leave[0] in room:
            room.remove(leave.popleft())
    
    return answer[1:]
