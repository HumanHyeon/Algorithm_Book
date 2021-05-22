#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
vector<int> solution(int n, vector<string> words) {
    int a,b,flag = 0;
    vector<int> answer;
    
    for(int i = 1; i < words.size(); i++){
        string p1 = words[i-1];
        string p2 = words[i];
        
        for(int j = 0; j < i; j ++){
            if(words[j] == words[i]){
                flag = 1;
                break;
            }
        }
     
        
        if(p1[p1.length() - 1] != p2[0])
            flag = 1;
        
        if(flag==1){
            a = (i % n) + 1;
            b = (i / n) + 1;
            answer.push_back(a);
            answer.push_back(b);
            return answer;
        }
    }
    
    return {0,0};
}
