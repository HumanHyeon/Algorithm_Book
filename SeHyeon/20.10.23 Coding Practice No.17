#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> log;
    map<string, string> table;          //id, nickname
    vector<tuple<string, string, string>> tmpLog;   //control, id, nickname

    for (auto element : record) {
        string control, id, nickname;
        stringstream ss(element);
        ss >> control;
        ss >> id;
        if (control != "Leave") ss >> nickname;
        
        if (control == "Enter") {
            if (table.find(id) == table.end()) {
                table.insert(make_pair(id, nickname));
                tmpLog.push_back(make_tuple(control, id, nickname));
            }
            else {
                table.find(id)->second = nickname;
                tmpLog.push_back(make_tuple(control, id, nickname));
            }
        }
        else if (control == "Leave")   tmpLog.push_back(make_tuple(control, id, table.find(id)->second));
        else if (control == "Change")  table.find(id)->second = nickname;
    }

    for (auto& element : tmpLog) {
        if (table.find(get<1>(element))->second != get<2>(element)) get<2>(element) = table.find(get<1>(element))->second;
        if (get<0>(element) == "Enter") log.push_back(get<2>(element) + "님이 들어왔습니다.");
        else if (get<0>(element) == "Leave") log.push_back(get<2>(element) + "님이 나갔습니다.");
    }
    return log;
}
