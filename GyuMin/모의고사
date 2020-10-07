//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;
    
    int first[5]={1,2,3,4,5};
    int second[8]={2,1,2,3,2,4,2,5};
    int third[10]={3,3,1,1,2,2,4,4,5,5};
    
    int F_count=0;
    int S_count=0;
    int T_count=0;
    
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i]==first[i%5])
            F_count++;
         if(answers[i]==second[i%8])
            S_count++; 
        if(answers[i]==third[i%10])
            T_count++;
    }
    if(F_count>=S_count&&F_count>=T_count)
        answer.push_back(1);

    if(S_count>=F_count&&S_count>=T_count)
        answer.push_back(2);

    if(T_count>=F_count&&T_count>=S_count)
        answer.push_back(3);

    return answer;
}
