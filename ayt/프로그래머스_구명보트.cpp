#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int start = 0;
    int end = people.size()-1;
    
    while(start<=end) {
        if(people[start] + people[end]<=limit) {
            start++;
            end--;
        }
        else
            end--;
        
        answer++;
    }
    
    return answer;
}
