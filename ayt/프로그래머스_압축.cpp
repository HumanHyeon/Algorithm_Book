#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int addNumber = 27;
    msg += "0";
    
    for(int i=0,j=1;i<msg.size();i+=j){
      for(j=1;j<msg.size()-i+1;++j){
        string tmp = msg.substr(i,j);
        if(m.find(tmp)==m.end()){
          if(tmp.size()==1){
            m[tmp] = tmp[0]-'A'+1;
            m[msg.substr(i,j+1)] = addNumber;
            answer.push_back(tmp[0]-'A'+1);
            ++addNumber;
            break;
          }
          m[tmp] = addNumber;
          answer.push_back((m.find(msg.substr(i,j-1)))->second);
          ++addNumber;
          --j;
          break;
        }
      }
    }
    answer.pop_back();
    
    return answer;
}
