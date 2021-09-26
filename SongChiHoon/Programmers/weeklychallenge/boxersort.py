def solution(weights, head2head):
    answer = []
    matchResult = []

    for personIndex, pastResults in enumerate(head2head) :
        myWeight = weights[personIndex]
        winNum, winBigger, matchNum = 0, 0, 0

        for resultIndex, result in enumerate(pastResults) :
            if result != "N" :
                matchNum += 1

            if result == "W" :
                winNum += 1
                if weights[resultIndex] > myWeight :
                    winBigger += 1
        
        winPercent = winNum / matchNum * 100 if matchNum != 0 else 0

        matchResult.append((personIndex + 1, winPercent, winBigger, myWeight))

    matchResult = sorted(matchResult, key=lambda x: (-x[1], -x[2], -x[3], x[0]))

    answer = [result[0] for result in matchResult]

    return answer