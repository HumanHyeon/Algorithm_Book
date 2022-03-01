def solution(word):
    ret = 0
    num = [781, 156, 31, 6, 1]
    
    for i in range(len(word)):
        ret += "AEIOU".find(word[i]) * num[i] + 1
    
    return ret