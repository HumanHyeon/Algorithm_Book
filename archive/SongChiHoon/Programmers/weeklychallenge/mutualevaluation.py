def solution(scores):
    answer = ''

    for firstIndex in range(len(scores)) :
        tempScore = []
        
        for secondIndex in range(len(scores)):
            tempScore.append(scores[secondIndex][firstIndex])

        if tempScore[firstIndex] == min(tempScore) and tempScore.count(tempScore[firstIndex]) == 1: 
            del tempScore[firstIndex]
        elif tempScore[firstIndex] == max(tempScore) and tempScore.count(tempScore[firstIndex]) == 1:
            del tempScore[firstIndex]

        mean = sum(tempScore) / len(tempScore)

        if mean >= 90 :
            answer += 'A'
        elif mean >= 80 :
            answer += 'B'
        elif mean >= 70 :
            answer += 'C'
        elif mean >= 50 :
            answer += 'D'
        else :
            answer += 'F'


    return answer