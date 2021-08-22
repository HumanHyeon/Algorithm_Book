import itertools # 순열 생성 라이브러리

N, K = map(int,input().split())
nums = list(map(int,input().split()))


count = 0
for kit in list(itertools.permutations((nums))):
    deadline = 500
    # 각 순열을 순회하며 3대 계산
    for k in kit:
        deadline = deadline - K + k
        # 순회하면서 한번이라도 500밑으로 내려가면 break
        if deadline < 500:
            break
    if deadline > 500:
        count += 1

print(count)