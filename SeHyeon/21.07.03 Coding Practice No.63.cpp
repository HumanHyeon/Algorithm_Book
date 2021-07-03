https://programmers.co.kr/learn/courses/30/lessons/12985

#include <iostream>
using namespace std;

int nextStep(int n) {
    float tmp;

    tmp = (float)n / 2;
    tmp -= n / 2;
    if (tmp > 0)
        return (n / 2 + 1);
    return (n / 2);
}

int solution(int n, int a, int b) {
    int answer = 1;

    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (true) {
        if (a % 2)
            if (a + 1 == b)
                break;
        a = nextStep(a);
        b = nextStep(b);
        answer++;
    }
    return answer;
}
