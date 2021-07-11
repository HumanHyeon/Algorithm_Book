n = int(input())
nl = list(map(int, input().split()))
maxSum, tmpSum = 0, 0

if max(nl) < 0:
     maxSum = max(nl)
else:
     for i in range(n):
          tmpSum = tmpSum + nl[i]
          if maxSum < tmpSum:
               maxSum = tmpSum
          if tmpSum < 0:
               tmpSum = 0
print(maxSum)
