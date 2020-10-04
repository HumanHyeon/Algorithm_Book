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
    vector<int> cnt = {0,0,0};
    
    for(int i=0;i<answers.size();++i){
        if(cnt[0] == spz[0].size()) cnt[0]=0;
        if(cnt[1] == spz[1].size()) cnt[1]=0; 
        if(cnt[2] == spz[2].size()) cnt[2]=0;
        
        if(answers[i] == spz[0][cnt[0]]) ++result[0];         //1번 수포자
        if(answers[i] == spz[1][cnt[1]]) ++result[1];         //2번 수포자
        if(answers[i] == spz[2][cnt[2]]) ++result[2];         //3번 수포자
        
        ++cnt[0];
        ++cnt[1];
        ++cnt[2];
    }
    
    int max = *max_element(result.begin(), result.end());
    for(int i=0;i<3;++i){
        if(max==result[i])
            answer.push_back(i+1);
    }
    
    return answer;
}
