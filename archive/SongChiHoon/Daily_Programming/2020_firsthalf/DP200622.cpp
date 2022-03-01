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

// 수 배열의 연속성을 바탕으로 접근

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int check(vector<int> numbers)
// {
//     vector<int> :: iterator iter;
//     int answer = 1;
//     if (find(numbers.begin(), numbers.end(), 1) == numbers.end()) // find()의 반환값이 vector의 끝값이다. == 찾는 원소가 vector속에 없다.
//         return 1;
//     if (find(numbers.begin(), numbers.end(), 2) == numbers.end())
//         return 2;

//     for (int answer = 2; answer < 9999; answer++)
//     {
//         int jack = (2 * answer - 1) / 2;
//         if (find(numbers.begin(), numbers.end(), jack) != numbers.end() && find(numbers.begin(), numbers.end(), jack+1) != numbers.end())
//         {
//             return jack++;
//         }
//         else
//         {
//             return jack;
//         }        
//     }        
// }


// 대칭수 찾기
int check(vector<int> num)
{
    vector<int> :: iterator iter;

    if(num[0] != 1)
        return 1;
    if(num[1] != 2)
        return 2;
    int i = 1;
    for (int answer = 3; answer < *num.end(); answer++)
    {
        iter = find(num.begin(), num.end(), answer);
        if (answer % 2 == 0 && find(num.begin(), num.end(), answer / 2 - i) != num.end() && find(num.begin(), num.end(), answer / 2 + i) != num.end())
        {
            
        }
    }
    
}

int main()
{
    vector<int> numbers;
    int temp;
    
    cout << "Input(end in negative number) : ";
    do
    {
        cin >> temp;
        if (temp < 0)
            break;
        numbers.push_back(temp);
    } while (1);

    sort(numbers.begin(), numbers.end());

    cout << "output : " << check(numbers);
    
}