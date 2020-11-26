#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s){
    int answer = 1000;
    
    //반복문 돌면서 몇단위로 자르는게 제일 길이가 짧아지는지 확인하는 과정//
    for(int i=1; i<=s.size();i++){
        int count = 1, result = 0;
        string before = "", present;
        
        for(int j=0;j<s.size();j+=i){
            present = s.substr(j,i);
            
            if(before ==present){
                count++;
            }
            else{
                if(count==1) result +=present.size();
                else  result+=(to_string(count.size()+present.size());
                              count=1;
                              }
                              before = present;
                              }
                              
                              if(count!=1) result += to_string(count).size();
                              
                              if(result < answer){
                                  answer = result;
                              }
                              }
                              return answer;
                              }
