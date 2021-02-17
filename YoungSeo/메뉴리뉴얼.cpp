#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    map<string,int> courseCount;
    map<int,int> Maxlength;
    
   
    for(string& str : orders){
        stable_sort(str.begin(), str.end());
    }
    
    for(string order : orders){
        for(int i: course){
            if(i>order.length()) break;
           
            for(int j=0; j<i; j++){
                str[j]='1';
            }
            do{
                string s= "";
                for(int k=0; k<str.length(); k++){
                    if(str[k]=='1'){
                        s+=order[k];
                        if(s.length()==i) break;
                    }
                }
                courseCount[s]++;
                Maxlength[i]=max(courseCount[s],Maxlength[i]);
            }while(prev_permutation(str.begin(), str.end()));
        }
        
    }
    for(auto e: courseCount){
        if(e.second>1){
            if(e.second == Maxlength[e.firtst.lenth()])
                answer.push_back(e.first);
        }
    }
    return answer;
}
