#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int v=0;
    for(int i=0; i<s.length(); i++) {
        if (s[i] == '(')
            v++;
        else
            v--;
        if (v < 0) {
            return false;
        }
    }
    
    
    
    if (v!=0)
        answer = false;
    return answer;
}
