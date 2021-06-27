#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start, end, mid;
    long long minTimes = 10000000000;
    long long maxTimes = 0;
    
    for (auto elem : times) {
        if(elem<minTimes) minTimes = elem;
        if(elem>maxTimes) maxTimes = elem;
    }
    
    start = minTimes;
    end = maxTimes * n;
    
    int i = 0;
    
    while(start<=end) {
        mid = (start + end) / n;
        
    }
    
    return answer;
}
