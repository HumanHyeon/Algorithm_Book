#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.rbegin(), citations.rend());
    while(1){
        if(citations[answer]<=answer||answer>citations.size()) break;
        ++answer;
    }
    
    return answer;
}
