#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    if ((a % 2 == 1 && a+1 == b) || (b % 2 == 1 && b+1 == a))
        return 1;
    else
        return 1 + solution(n/2, (a+(a%2))/2, (b+(b%2))/2);
}
