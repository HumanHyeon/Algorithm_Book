// 2차 정수 배열(2D int array)가 주어지면, 
// 소용돌이 모양으로 원소들을 프린트하시오. 
// 예제를 보시오.



// Given a 2D integer array, 
// print all elements in a circular spiral shape starting from [0][0]. 
// See example.

// 예제)

// input:

// [[1, 2, 3],

// [8, 9, 4],

// [7, 6, 5]]



// Output:

// 1, 2, 3, 4, 5, 6, 7, 8, 9

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE 3

int input[SIZE][SIZE] = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

int main() {

    vector<int> box;

    cout << "Input:" << endl << "[";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "[";
        for (int j = 0; j < SIZE; j++)
        {
            cout << input[i][j] << " ";
        }
        cout <<"]" << endl;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            box.push_back(input[i][j]);
        }        
    }

    sort(box.begin, box.end);
    reverse(box.begin, box.end);

    cout << "Output : ";

    for (vector<int>::iterator it = box.begin; it != box.end; it++)
    {
        cout << *it << ", ";
    }  

    return 0;
}