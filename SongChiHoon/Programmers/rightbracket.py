def solution(s):
    answer = True
    bracketlist = []
    for bracket in s:
        if bracket == "(":
            bracketlist.append(bracket)
            continue
        if bracket == ")":
            if len(bracketlist) == 0:
                answer = False
                continue
            else:
                bracketlist.pop()
                continue
    if len(bracketlist) != 0:
        answer = False
    if answer == True:
        return True
    else:
        return False
        
    print('Hello Python')

print(solution("(())"))