// 정수 배열(int array)이 주어지면 0이 아닌 정수 순서를 유지하며 
//모든 0을 배열 오른쪽 끝으로 옮기시오. 
//단, 시간복잡도는 O(n), 공간복잡도는 O(1)여야 합니다.

// Given an integer array, move all the 0s to the right of the array without changing the order of non-zero elements.

// 예제)

// Input: [0, 5, 0, 3, -1]

// Output: [5, 3, -1, 0, 0]


// Input: [3, 0, 3]

// Output: [3, 3, 0]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> input, output;
    int temp;
    int i = 0;
    
    cout << "Input";

    while (temp)
    {
        cin >> temp;
        input.push_back(temp);
    }
    
    sort(input.begin(), input.end(), output);

    reverse(output.begin(), output.end());

    cout << "Output : ";

    while (i == size(output))
    {
        cout << output[i];
        i++;
    }
    

    return 0;
}