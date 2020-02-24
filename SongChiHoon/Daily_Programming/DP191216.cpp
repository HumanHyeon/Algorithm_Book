/*
정수 배열(int array)가 주어지면 가장 큰 이어지는 원소들의 합을 구하시오. 단, 시간복잡도는 O(n).

Given an integer array, find the largest consecutive sum of elements.

예제}

Input: [-1, 3, -1, 5]

Output: 7 // 3 + (-1) + 5


Input: [-5, -3, -1]

Output: -1 // -1


Input: [2, 4, -2, -3, 8]

Output: 9 // 2 + 4 + (-2) + (-3) + 8

해결전략
1. 입력값의 가장 큰 두 값을 먼저 찾는다.
2. 입력 배열에서 두 값 사이에 값들을 찾는다.
3. 그 값들의 합을 구한다.
*/
#include <iostream>
using namespace std;

#define biggest[]

//가장 큰 두 값을 찾는 함수
int Search(int *input, int *big, int count)
{
    if(big[0] > input[count])
    return Search(input, big, count++);
    if(big[0] < input[count])
    {
        swap(big[0], big[1]);
        swap(big[0], input[count]);
    }
}

int main()
{
    int big[2], temp[5], count = 0;
    int input1[] = {-1, 3, -1, 5}; int input2[] = {-5, -3, -1}; int input3[] = {2, 4, -2, -3, 8};

    Search(input1, big, count);

    return 0;
}