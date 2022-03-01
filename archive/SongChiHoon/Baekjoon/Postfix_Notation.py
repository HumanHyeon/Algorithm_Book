S = input()

# 연산자 우선순위 정하는 함수
def priority(operator) :
    if operator == '+' or operator == '-' :
        return 1
    elif operator == '*' or operator == '/' :
        return 2
    else :
        return 0

stack = []
result = ''

for i in S :
    if i.isalpha() :
        result += i
        continue

    if i == '(' :
        stack.append(i)
    elif i == ')' :
        while(True) :
            if stack and stack[-1] != '(' :
                result += stack.pop()
            else :
                stack.pop()
                break
    else :
        while(True) :
            if stack and (priority(stack[-1]) >= priority(i)) :
                result += stack.pop()
            else :
                stack.append(i)
                break

while(True) :
    if stack :
        result += stack.pop()
    else :
        break

print(result)
