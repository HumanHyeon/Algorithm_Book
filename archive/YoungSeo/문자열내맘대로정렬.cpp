#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int x;
 
bool Ssort(string a, string b){
    if(a.at(x)!=b.at(x)){
        return a.at(x) < b.at(x);   
    }else{
        return a < b;   
    }
}
 
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;
    x = n;
    sort(answer.begin(),answer.end(),Ssort);
    return answer;
}
