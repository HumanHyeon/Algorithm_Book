def solution(s):
    count = 1
    zerocount = 0
    size = 0

    while s != '1' :
        temp = ''
        for i in s:
            if i == '1' :
                temp += i
            else :
                zerocount += 1
                
        size = len(temp)
        if size > 1:
            count += 1

        s = str(format(size, 'b'))
        
    answer = [count, zerocount]
    return answer