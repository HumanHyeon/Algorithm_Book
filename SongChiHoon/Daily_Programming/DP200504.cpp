// O(n log n)시간 복잡도를 가진 정수 배열 정렬 알고리즘을 구현하시오.



// Implement an O(n log n) time complexity sorting algorithm.

 

// 예제)

// Input: [3, 1, 5, 6]

// Output: [1, 3, 5, 6]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> array;
    int a;

    for (int i = 0; i < 4; i++)
    {
        cin >> a;
        array.push_back(a);
    }

    sort(array.begin(), array.end());
    
}