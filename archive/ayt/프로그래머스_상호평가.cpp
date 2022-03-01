#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i=0;i<scores.size();i++) {
        int mine = scores[i][i];
        int sum = 0;
        vector<int> tmpscore;
        bool maxck = true,minck = true;
        
        for(int j=0;j<scores[i].size();j++){
            if(j==i) continue;
            tmpscore.push_back(scores[j][i]);
        }
        
        if(*max_element(tmpscore.begin(), tmpscore.end()) < mine) maxck = false;
        if(*min_element(tmpscore.begin(), tmpscore.end()) > mine) minck = false;
        
        if(maxck && minck) tmpscore.push_back(mine);
        
        for(int j=0;j<tmpscore.size();j++)
            sum += tmpscore[j];
        int avg = sum/tmpscore.size();
        
        if(avg>=90) answer += "A";
        else if(90>avg && avg>=80) answer += "B";
        else if(80>avg && avg>=70) answer += "C";
        else if(70>avg && avg>=50) answer += "D";
        else answer += "F";
    }
    
    return answer;
}
