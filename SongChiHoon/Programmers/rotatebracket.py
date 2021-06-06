def solution(s):
    answer = 0
    dic = {'{':'}', '[':']', '(':')'}
    
    for i in range(len(s)):
        
        right = list(s[i:] + s[:i])
        left = []
        
        while right:
            
            temp = right.pop(0)
            
            if not left:
                left.append(temp)
            
            else:
                if left[-1] in ['}', ')', ']']:
                    break    
                if dic[left[-1]] == temp:
                    left.pop()
                else:
                    left.append(temp)
        
        if not left:
            answer += 1
            
    return answer
