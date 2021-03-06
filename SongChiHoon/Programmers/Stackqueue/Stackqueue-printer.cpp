#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int bestpriorities = 1;
    vector<int> :: iterator iter;

    // vector를 한번 순회하며 최고 중요도 값 찾기
    for (int i = 0; i < priorities.size(); i++)
    {
        if(priorities[i] > bestpriorities)
            bestpriorities = priorities[i];
    }
    // vector iterator로 location값 찾기
    for (iter = priorities.begin(); iter < priorities.end(); iter++)
    {
        if(*iter != bestpriorities)
        {
            if(location == 0)
                location = priorities.size();
            location--;
        }
        if (*iter == bestpriorities)
            answer = location + 1;
    }
    
    return answer;
}