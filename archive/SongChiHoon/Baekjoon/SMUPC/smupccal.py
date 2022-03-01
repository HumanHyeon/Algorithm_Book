import sys

input = sys.stdin.readline
N = int(input())
t = input()
tmp = ""
g = []

for i in t:
  
    if i in "SMUPC":
        if tmp:
            g.append(int(tmp))
        g.append(i)
        tmp = ""
    else:
        tmp += i

g += [1]
ret = 0
idx = 0
ans = []

while idx < len(g)-1:
    if type(g[idx]) == int:
        ret = g[idx]
        idx += 1

    else:
        c = g[idx]

        if c == "S":
            ret -= g[idx+1]
            idx += 2

        elif c == "M":
            ret *= g[idx+1]
            idx += 2

        elif c == "U":
            if ret < 0:
                ret *= -1
                ret //= g[idx+1]
                ret *= -1

            else:
                ret //= g[idx+1]
            idx += 2

        elif c == "P":
            ret += g[idx+1]
            idx += 2

        elif c == "C":
            ans.append(ret)
            idx += 1

print(*ans if ans else ["NO OUTPUT"])
