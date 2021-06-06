#include <string>
#include <vector>

using namespace std;

bool promising(string s) {
    int n1=0, n2=0, n3=0;
    for(int i=0;i<s.size();i++) {
        if(n1<0 || n2<0 || n3<0) break;
        switch (s[i]) {
            case '(':
                n1 += 1;
                break;
            case ')':
                n1 -= 1;
                break;
            case '[':
                n2 += 1;
                break;
            case ']':
                n2 -= 1;
                break;
            case '{':
                n3 += 1;
                break;
            case '}':
                n3 -= 1;
                break;
        }
    }
    
    if(!n1 && !n2 && !n3) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    if(promising(s)) ++answer;
    for(int i=0;i<s.size()-1;++i) {
        string tmp = "";
        string e = "";
        e = s[0];
        s.erase(0,1);
        tmp = s + e;
        
        if(promising(tmp)) ++answer;
        s = tmp;
    }
    
    return answer;
}
