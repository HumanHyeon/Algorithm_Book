def solution(n):
    count = 0
    while n > 0:
        quotient, remainder = divmod(n, 2)
        n = quotient
        if remainder != 0:
            count += 1
    return count
