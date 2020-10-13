#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> spz = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    vector<int> result = {0,0,0};
    
    for(int i=0;i<answers.size();++i){
        if(answers[i] == spz[0][i%5]) ++result[0];
        if(answers[i] == spz[1][i%8]) ++result[1];
        if(answers[i] == spz[2][i%10]) ++result[2];
    }
    
    int max = *max_element(result.begin(), result.end());
    for(int i=0;i<3;++i){
        if(max==result[i])
            answer.push_back(i+1);
    }
    
    return answer;
}
