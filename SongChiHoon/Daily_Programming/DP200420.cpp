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
using namespace std;

//horizontal_point 가로 값, vertical_point 세로 값
int movingpart(int **input, int vertical_point = 0, int horizontal_point = 0, string direction = "right"){

    cout << input[vertical_point][horizontal_point] << " ";
    input[vertical_point][horizontal_point] = NULL;

    if (direction == "right" && input[vertical_point][horizontal_point + 1] == NULL)    direction = "down";
    if (direction == "down" && input[vertical_point + 1][horizontal_point] == NULL)     direction = "left";
    if (direction == "left" && input[vertical_point][horizontal_point - 1] == NULL)     direction = "up";
    if (direction == "up" && input[vertical_point - 1][horizontal_point] == NULL)       direction = "right";    

    if (input[vertical_point][horizontal_point + 1] != NULL && direction == "right")
        movingpart(input, vertical_point, horizontal_point + 1);
    if (input[vertical_point + 1][horizontal_point] != NULL && direction == "down")
        movingpart(input, vertical_point + 1, horizontal_point);
    if (input[vertical_point][horizontal_point - 1] != NULL && direction == "left")
        movingpart(input, vertical_point, horizontal_point - 1);
    if (input[vertical_point - 1][horizontal_point] != NULL && direction == "up")
        movingpart(input, vertical_point - 1, horizontal_point);
}

int main() {

    int horizontal, vertical;

    cout << "Input horizontal length : ";   cin >> horizontal;
    cout << endl << "Input vertical length : ";     cin >> vertical;

    // 2D array dynamic allocation
    int **input = new int*[vertical];
    for (int i = 0; i < vertical; i++)
    {
        input[i] = new int[horizontal];
    }
    

    for (int verticalx = 0; verticalx < vertical; verticalx++)
    {
        for (int horizontalx = 0; horizontalx < horizontal; horizontalx++)
        {
            cin >> input[verticalx][horizontalx];
        }
    }

    cout << "Input:" << endl << "[";

    for (int i = 0; i < vertical; i++)
    {
        cout << "[";
        for (int j = 0; j < horizontal; j++)
        {
            cout << input[i][j] << " ";
        }
        cout <<"]" << endl;
    }

    cout << "]";

    cout << "Output : ";

    movingpart(input);

    return 0;
}