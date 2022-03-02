#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> tmp(n+1);
    tmp[1]=1;
    tmp[2]=2;
    
    if(n==1)
        return tmp[1];
    if(n==2)
        return tmp[2];
    
    for(int i=3;i<=n;++i){
        tmp[i]=(tmp[i-1]+tmp[i-2])%1234567;
    }
    answer=tmp[n];
    
    return answer;
}

//약간 문제가 이상함
