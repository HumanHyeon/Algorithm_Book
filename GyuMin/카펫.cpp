//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int B=((brown-4)/2);
    
    for(int i=B;i>=(B-i);i--)
        if(i*(B-i)==yellow)
        {
            answer.push_back(i+2);
            answer.push_back(B-i+2);
        }
    
    return answer;
}
