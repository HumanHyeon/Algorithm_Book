// 정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의 인덱스를 찾으시오.

// 단, 시간복잡도 O(n) 여야 합니다.

// Given an array of integers and a target integer, find two indexes of the array element that sums to the target number.

// 예제)

// Input: [2, 5, 6, 1, 10], 타겟 8

// Output: [0, 2] // 배열[0] + 배열[2] = 8

#include <iostream>
#define SIZE 5
using namespace std;

int main()
{
    int target = 8;
    int input[SIZE] = {2, 5, 6, 1, 10};
    int result_value = 0;

    cout << "Input : [";
    for(int i = 0; i < SIZE; i++)
    {
        cout << input[i] << " ";
    }
    cout << "]" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        result_value = input
    }

    return 0;
}