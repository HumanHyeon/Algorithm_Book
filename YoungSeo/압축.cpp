#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int> > dic;
int isInDic(string cur){ //사전에 있으면 색인번호를 리턴하는 함수 
    for(int i=0; i<dic.size(); i++){
        if(dic[i].first.size() != cur.size()) continue;
        if(dic[i].first == cur) return dic[i].second;
    }
    return 0;
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    //길이가 1인 모든 단어를 포함하도록 사전을 초기화
    for(int i=0; i<26; i++) dic.push_back(make_pair(string(1, 'A'+i), i+1));
    
    int sNum= 27;
    string cur, before; 
    for(int i=0, j=0; i<msg.size();){
    
        for(j=1; i+j<=msg.size(); j++){ // 현재 입력과 일치하는 가장 긴 문자열 찾기
            cur = msg.substr(i, j); 
            if(isInDic(cur)) { 
                before = cur; 
                continue;
            } else { // 사전에 없으면 answer에 색인번호 추가
                answer.push_back(isInDic(before));
                break;
            }
        }
        dic.push_back(make_pair(cur, sNum++));
        i+=(j-1); //입력에서 w길이만큼 제거
    }
    answer.push_back(isInDic(cur));
    return answer;
}
