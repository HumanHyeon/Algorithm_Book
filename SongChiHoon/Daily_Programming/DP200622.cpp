// 정렬된 양수(positive integer) 배열이 주어지면, 배열 원소들의 합으로 만들수 없는 가장 작은 양수를 구하시오.
// 단, 시간복잡도는 O(n) 이여야 합니다.

// Given an array of positive integers, find the smallest positive integer that cannot be created by adding elements in the array.

// input: [1, 2, 3, 8]
// output: 7

// // 1 = 1
// // 2 = 2
// // 3 = 3
// // 4 = 1 + 3
// // 5 = 2 + 3
// // 6 = 1 + 2 + 3
// // 7 = 불가능

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int> numbers)
{
    int answer = 1;
    bool checking;

    if (*numbers.begin() > 1)
    {
        return *numbers.begin() - 1;
    }

    for (int i = 0; i < 9999; i++)
    {
        if (numbers[i] == answer)
            checking = true;
        if (numbers[i] + numbers[i+1] == answer)
        {
            checking = true;
        }
        if (numbers[i] + numbers[i+1] + numbers[i+2] == answer)
        {
            checking = true;
        }
        
        // 아 몰라~
        
    }
    

    return answer;
}

int main()
{
    vector<int> numbers;
    int temp;
    
    do
    {
        cin >> temp;
        numbers.push_back(temp);
    } while (temp > 0);

    sort(numbers.begin(), numbers.end());

    cout << "output : " << check(numbers);
    
}