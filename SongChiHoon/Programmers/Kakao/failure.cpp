#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b){
    return a > b ? true : false;
}

bool pairCompare(const pair<int,double> &a, const pair<int, double> &b){
    if(a.second > b.second) return true;
    else if(a.second == b.second ){
        if(a.first < b.first) return true;
        else return false;
    } else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<int,double>> fail;
    vector<int> answer; 
    
    sort(stages.begin(), stages.end(), compare);

    int num = 1;
    while(num <= N){
        int total = 0;
        int stay = 0;
        for(int i = 0; i < stages.size(); i++){
            if(stages[i] < num) break;
            if(stages[i] >= num) total++; 
            if(stages[i] == num) stay++; 
        }
        double rate; 
        if(stay == 0){
            rate = 0; 
        } else {
            rate = (double)stay / total;
        }
        fail.push_back(make_pair(num,rate));
        num++;
    }
    
    sort(fail.begin(), fail.end(), pairCompare); 

    for(int i = 0; i < N; i++){
        answer.push_back(fail[i].first);
    }
    return answer;
}