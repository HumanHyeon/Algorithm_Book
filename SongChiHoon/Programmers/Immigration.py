def impossible(n, middle, times):
    return sum([middle // x for x in times]) < n

def solution(n, times):
    left, right = 1, max(times)*n
    while left < right:
        middle = (left + right) // 2
        if impossible(n, middle, times): 
            left = middle + 1
        else: 
            right = middle
    return left
