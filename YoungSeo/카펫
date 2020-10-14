#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int width = brown + yellow;
    
    for(int a=3;a<width;a++){
        if(width%a==0){
            
            int b= width/a;
        if(a<b)
            continue;
            int yellownum=(a-2) *(b-2);
            int brownnum= width - yellownum;
            if(yellownum == yellow && brownnum==brown){
                answer.push_back(a);
                answer.push_back(b);
                break;
            
            }
        }
    }
    return answer;
}
