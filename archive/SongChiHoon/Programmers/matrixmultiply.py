def solution(arr1, arr2):
    answer = []
#     middleSet = []
    
#     for i in range(len(arr2[0])) :
#         for j in range(len(arr1)) :
#             middleSet.append(0)
#         answer.append(middleSet)
#         middleSet = []
        
    answer = [[0 for _ in range(len(arr2[0]))] for _ in range(len(arr1))]
    
    for i in range(len(arr1)):
        for j in range(len(arr2[0])):
            for k in range(len(arr1[0])):
                answer[i][j] += (arr1[i][k] * arr2[k][j])
        
    return answer
