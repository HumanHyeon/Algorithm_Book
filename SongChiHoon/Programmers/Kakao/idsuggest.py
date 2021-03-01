def solution(new_id):
    answer = new_id
    # 5번 조건
    if len(answer) == 0:
        answer += 'a'

    # 1번 조건
    answer = answer.lower()

    # 2번 조건
    table = str.maketrans("~!@#$%^&*()=+[{]}:?,<>/","                       ")
    answer = answer.translate(table)
    answer = "".join(answer.split())

    # 3번 조건
    while True:
        if answer.find("..") != -1:
            answer = answer.replace('..','.')
        else:
            break

    # 4번 조건
    while answer[0] == '.' or answer[-1] == '.':
        answer = answer.strip('.')
        if len(answer) == 0:
            answer += 'a'
    
    # 6번 조건
    if len(answer) > 15:
        answer = answer[:15]
        while answer[0] == '.' or answer[-1] == '.':
            answer = answer.strip('.')
            if len(answer) == 0:
                answer += 'a'

    # 7번 조건
    while len(answer) <= 2:
        answer += answer[-1]
        
    return answer