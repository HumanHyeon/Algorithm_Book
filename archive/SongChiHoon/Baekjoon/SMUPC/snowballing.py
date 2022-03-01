import sys
input=sys.stdin.readline

# N은 앞마당 길이, M은 대회의 시간
N, M = map(int, input().split())

# 첫 시작이 0부터 이므로 0을 추가하고 입력
A = [0] + list(map(int, input().split()))

def DFS(index, size, time):
    # 나중에 반환할 정답
    global ret

    #시간이 M을 초과하면 끝
    if time > M : return

    #시간을 초과하지 않으면 눈덩이 크기 비교해서 최대값 저장
    if time <= M :
        ret = max(ret, size)

    #눈덩이 굴리기
    if index <=N-1:
        DFS(index+1, size+A[index+1], time+1)

    #눈덩이 던지기
    if index <= N-2:
        #눈덩이 크기는 절반
        DFS(index+2, size//2 + A[index+2], time+1)

ret = -1

DFS(0,1,0)

print(ret)
