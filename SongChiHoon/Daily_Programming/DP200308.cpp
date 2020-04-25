// 정수 배열(int array)과 정수 N이 주어지면, N번째로 큰 배열 원소를 찾으시오.



// Given an integer array and integer N, find the Nth largest element in the array.



// 예제)

// Input: [-1, 3, -1, 5, 4], 2

// Output: 4



// Input: [2, 4, -2, -3, 8], 1

// Output: 8



// Input: [-5, -3, 1], 3

// Output: -5

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int targetnum, temp, answer;
    vector<int> input;

    cout << "배열 입력";
    
    while (temp)
    {
        cin >> temp;
        input.push_back(temp);
    }

    int *ret = new int[size(input)];

    sort(input.begin(), input.end(), ret);    
    
    cout << "찾으려는 N번째 큰 수 입력";
    cin >> targetnum;

    for (int i = 0; i < targetnum; i++)
    {
        answer = input.pop_back;
    }

    cout << "Output : " << answer;

    return 0;
}