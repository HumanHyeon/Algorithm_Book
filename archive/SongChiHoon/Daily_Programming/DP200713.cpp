// 백만개의 정수가 들어있는 배열을 가장 빨리 정렬하시오. 모든 정수는 1조보다 작습니다.

// 힌트) 퀵소트 아님.

// Sort an array with million integers.

#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

# define SIZE 1000000

int input[SIZE];

void numbermaking() {

    srand((unsigned int)time(0));

    for(int i = 0; i < SIZE; i++)
        input[i] = rand() % SIZE;

}

// radix sort(기수 정렬)
// int main() {

//     int temp[SIZE];
//     int numbers[10];

//     numbermaking();

//     numbers[input[0] % 10];

//     for (int i = 0; i < SIZE; i++)
//     {
//         input[i] % 10 > temp[i] ? ;
//     }
    

// }

// counting sort(카운팅 정렬)
int main() {
    numbermaking();

    int biggest = 0;
    for (int i : input)
        i > biggest ? biggest = i : biggest = biggest;
    
    int temp[SIZE + 1] = {};

    
}