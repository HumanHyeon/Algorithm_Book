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
    sort(stages.begin(), stages.end(), compare); //스테이지를 내림차순으로 정렬

    int num = 1; 
    double rate; //실패율
    while(num <= N){ //N+1은 고려하지 않음
        int total = 0; //스테이지를 통과한 전체 인원 수
        int notpass = 0; // 통과하지 못한 사람 수
        for(int i = 0; i < stages.size(); i++){
            if(stages[i] < num) break; 
            if(stages[i] >= num) total++; 
            if(stages[i] == num) notpass++; 
        }
       
        if(notpass == 0){
            rate = 0; 
        } else {
            rate = (double)notpass / total;
        }
        fail.push_back(make_pair(num,rate));
        num++;
    }
    
    sort(fail.begin(), fail.end(), pairCompare); //실패율이 높고 인덱스가 낮은 순으로 정렬
    for(int i = 0; i < N; i++){
        answer.push_back(fail[i].first);
    }
    return answer;
}
