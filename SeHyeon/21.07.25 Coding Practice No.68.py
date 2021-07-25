https://www.acmicpc.net/problem/21734
  
inputStr = input()

for i in range(len(inputStr)):
     asci = str(ord(inputStr[i]))
     cycle = 0
     outputstr = ""
     for j in asci:
          cycle = cycle + int(j)
     outputStr = inputStr[i] * cycle
     print(outputStr)
