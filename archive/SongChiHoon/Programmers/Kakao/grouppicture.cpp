#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> character = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do {
        answer++;
        
        for(int i = 0; i < n; i++) {
            char front = data[i][0];
            char back = data[i][2];
            int count = data[i][4] - '0';
            int frontIndex = 0, backIndex = 0, dist = 0;
            bool check = true;
            
            for(int j = 0; j < 8; j++) {
                if(character[j] == front)
                    frontIndex = j;
                if(character[j] == back)
                    backIndex = j;
            }
            
            dist = frontIndex < backIndex ? backIndex - frontIndex - 1 : frontIndex - backIndex - 1;
            
            if(data[i][3] == '=') {
                if(dist == count)
                    check = true;
                else
                    check = false;
            }
            else if(data[i][3] == '>') {
                if(dist > count)
                    check = true;
                else
                    check = false;
            }
            else {
                if(dist < count)
                    check = true;
                else
                    check = false;
            }
            
            if(!check) {
                answer--;
                break;
            }
        }
    }while(next_permutation(character.begin(), character.end()));
    
    return answer;
}