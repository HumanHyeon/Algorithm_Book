#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    int answer = 1;
    //종류별로 분류
    for(int i = 0; i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    //처음부터 순회
    for(auto i = m.begin(); i != m.end(); i++){
        answer *= ((i->second) + 1);
    }
    
    return answer - 1; //아무것도 안입는 경우 1 제외
}
