#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long maxTimes = 0;
    
    for (auto elem : times) 
        if(elem>maxTimes) maxTimes = elem;
    
    long long start = 1;
    long long end = maxTimes * n;
    long long i;
    
    while(start<=end) {
        long long mid = (start + end) / 2;
        i = 0;
        
        for(auto elem : times) {
            i += mid / elem;
            if(i>=n) end = mid - 1;
        }
        if(i<n) start = mid + 1;
    }
    
    return start;
}
