https://programmers.co.kr/learn/courses/30/lessons/12909

#include <iostream>
using namespace std;

bool solution(string s){
    int leftCount = 0;
    
    for (int i = 0; i < s.size(); i++) 
        if (s[i] == '(')  leftCount++; 
        else
            if (leftCount == 0) return false;
            else leftCount--;
   
    if (leftCount == 0)  return true;
    else return false;
}
