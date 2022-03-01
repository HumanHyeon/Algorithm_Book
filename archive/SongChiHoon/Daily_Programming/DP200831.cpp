// 1~N 까지 있는 정수 배열에 원소 하나가 없어졌습니다. 없어진 원소의 값을 구하시오.



// Given an integer array of 1~N except one number, find the missing integer.

#include <iostream>
#include <ctime>
using namespace std;

int main() {

    int N;    int missing_number;
    cout << "Type N : ";    cin >> N;

    int *numbers = new int[N];

    for (int i = 0; i < N; i++) {
        numbers[i] = i + 1;
    }

    srand((unsigned int)time(0));
    missing_number = rand() % N;

    numbers[missing_number] = 0;

    int i = 0;    int point;

    do {
        point = numbers[i];
        i++;
    } while ( point != 0 );

    cout << "answer is " << --i;

    return 0;
}