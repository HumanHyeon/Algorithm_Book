#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max, i = 0;
    bool check = false;
    vector<int> tmp(priorities);
    
    sort(tmp.begin(), tmp.end());
    max = tmp[tmp.size()-1];
    
    while(1){
        if(priorities[location]==-1)
            break;
        if(priorities[i] == max){
            priorities[i] = -1;
            ++answer;
            check = true;
        }
        else{
            if(i == priorities.size()-1)
                i = 0;
            else
                ++i;
        }
        if(check==true){
            tmp.pop_back();
            max = tmp[tmp.size()-1];
            check = false;
        }
    }
    
    return answer;
}
