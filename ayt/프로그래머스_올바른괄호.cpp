#include <string>
#include <iostream>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(string s) {
    int cnt = 0;
    
    if(s[0] == ')') return false;
    else if(s[s.size()-1] == '(') return false;
    
    
    for(int i=0;i<s.size();++i){
      if(s[i]=='(') ++cnt;
      else if(s[i]==')') --cnt;
      
      if(cnt < 0) return false;
    }
    
    if(cnt ==0) return true;
    else return false;
}

int main() {
  string s = "()))((()";
  
  cout << solution(s);
}
