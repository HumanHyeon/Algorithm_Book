// 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.

// Fibonacci sequence starts with 0 and 1 where each fibonacci number is a sum of two previous fibonacci numbers. Given an integer N, find the sum of all even fibonacci numbers.

// 예제)

// Input: N = 12

// Output: 10 // 0, 1, 2, 3, 5, 8 중 짝수인 2 + 8 = 10.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, count;
    int foundationnum[2] = {0, 1};
    vector<int> mainplace = {0, 1};

    cout << "Input ";   cin >> N;

    for (int i = 2; N > mainplace[i-2] + mainplace[i-1]; i++)
    {
        N = mainplace[i-2] + mainplace[i-1];
        mainplace.push_back(mainplace[i-2] + mainplace[i-1]);
        count = i;
    }

    while (mainplace.back() != 0)
    {
        mainplace.pop_back(mainplace.back() + 1)
    }
    
    
    

    return 0;
}