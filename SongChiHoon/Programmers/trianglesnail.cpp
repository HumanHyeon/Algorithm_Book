#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    // 임시 배열 공간 할당
    int size = 0;
    for(int i = 1; i <= n; i++) { size += i; }
    int *temp = new int[size];
    
    //왼쪽 내려가는 대각선
    int laststartpoint;
    int num = 1;
    for (int i = 0; num != n; num++) {
        temp[i] = num;
        i += num;
        laststartpoint = i;
    }

    //삼각형의 밑변
    int input = n;
    for (int i = laststartpoint; i <= size; i++) { temp[i] = input++; }

    //

    answer.assign(temp, temp + size);
    return answer;
}