def solution(arr1, arr2):
    answer = [[]]   # size: arr2x x arr1y
    
    arr1x = len(arr1[0])
    arr1y = len(arr1)
    arr2x = len(arr2[0])
    arr2y = len(arr2)

    for ypos in range(arr1y):
        for xpos in range(arr2x):
            element = 0
            # get element
            for x in range(arr1[ypos]):
                element += arr1[ypos][x] * arr2[x][ypos]
            answer[ypos].append(element)
    
    
    return answer
