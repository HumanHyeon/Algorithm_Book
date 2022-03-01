// 정수 배열(int array)이 주어지면 두번째로 큰 값을 프린트하시오.



// Given an integer array, find the second largest element.



// 예제)

// Input: [10, 5, 4, 3, -1]

// Output: 5



// Input: [3, 3, 3]

// Output: Does not exist.

#include <iostream>
using namespace std;

int main()
{
    int *input = new int[5];

    cout << "Input : [";

    for(auto n : input[])
    {
        cin >> input[n];
    }

    delete input[];
    return 0;
}