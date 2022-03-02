#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
vector<int> solution(int n, vector<string> words) {
    int flag = 0;
    int a = 0;
    int b = 0;
    vector<int> answer;
    
    for(int i = 1; i < words.size(); i++){
        string first = words[i-1];
        string second = words[i];
        
        for(int j = 0; j < i; j ++){
            if(words[j] == words[i]){
                flag = 1;
                break;
            }
        }
        
        int len_first = first.length();
        
        if(first[len_first - 1] != second[0])
            flag = 1;
        
        if(flag){
            a = (i % n) + 1;
            b = (i / n) + 1;
            answer.push_back(a);
            answer.push_back(b);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}