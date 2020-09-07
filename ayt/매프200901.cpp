#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int sum1, sum2;
int findMiss(int inp[],int n) {
    for (int i = 0; i < n; ++i)
        sum1 += inp[i];

    srand((unsigned int)time(NULL));
    inp[rand() % n] = NULL;
    
    for (int i = 0; i < n; ++i)
        sum2 += inp[i];

    return sum1 - sum2;
}

int main() {
    int input[100];
    int size = sizeof(input) / sizeof(int);

    for (int i = 0; i < 100; ++i)
        input[i] = i + 1;

    cout << findMiss(input, size);

    return 0;
}
