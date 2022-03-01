#include <iostream>
#include <cmath>

using namespace std;

int powI(int n, int exp) {
    return (int)pow((double)n, (double)exp);
}

int solution(int n)
{
    int ans = 0;
    
    int i = 0;
    int lower, higher;
    
    while (powI(2, i) <= n)
        i++;
    
    lower = n - powI(2, i-1);
    higher = powI(2, i) - n;
    
    ans = lower > higher ? lower : higher;
    
    return ans;
}
