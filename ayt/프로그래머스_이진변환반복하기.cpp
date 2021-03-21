#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int cnt2 = 0;
    string tmp = "";
    
    while(1){
      if(tmp.size()==1) break;
      ++cnt2;
      
      for(int i=0;i<s.size();++i){
        if(s[i]=='1'){
          tmp += "1";
        }
      }
      int size = tmp.size();
      tmp = "";
      while(size>0){
        if(size%2==1) tmp+="1";
        else tmp+="0";
        size /=  2;
      }
      reverse(tmp.begin(), tmp.end());
      cout << tmp << endl;
    }
    
    answer.push_back(cnt2);
    answer.push_back(cnt);
    
    return answer;
}

int main() {
  string s = "110010101001";
  
  for(auto elem:solution(s))
  cout << elem << " ";
}
