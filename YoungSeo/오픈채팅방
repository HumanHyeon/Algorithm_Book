#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
map<string, string> m;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    string id, name, key;
    stringstream ss;
    
    for(int i=0;i<record.size();i++)
    {
        ss.str(record[i]);
        ss >> key; ss >> id; ss >> name;
        if(key == "Enter" ){
            m[id] = name;
            answer.push_back(name + "님이 들어왔습니다.");
        }
         else if(key == "Leave"){
            answer.push_back(name + "님이 나갔습니다.");
             m[id] = name;}
        else(key == "Change"){
            ss>>id;
            ss>>name;
            m[id]= name;    
        }
        



    return answer;}
}
