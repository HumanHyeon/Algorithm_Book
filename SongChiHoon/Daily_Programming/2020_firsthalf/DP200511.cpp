// 정렬(sort)된 정수 배열과 정수 n이 주어지면, 배열안에 n이 있는지 체크하시오. 시간복잡도를 최대한 최적화하시오.



// Given a sorted integer array and an integer N, check if N exists in the array.

 

// 예제)

// Input: [1, 2, 3, 7, 10], 7

// Output: true



// Input: [-5, -3, 0, 1], 0

// Output: true

// ﻿

// Input: [1, 4, 5, 6, 8, 9], 10

// Output: false

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchingnum(vector<int> container, int searchnum)
{
    if(*container.end() == searchnum)
        return true;
    if(container.empty() == true)
        return false;
    else
        container.pop_back();
        searchingnum(container, searchnum);
}

int main()
{
    vector<int> container;
    int a;
    do
    {
        cin >> "Input Array : " >> a;
        if(a < 0)
            break;
        container.push_back(a);
    } while (1);

    int searchnum;
    cin >> "Target Number : " >> searchnum;

    bool answer;

    answer = searchingnum(container, searchnum);

    cout << answer;
}