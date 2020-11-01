//https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, string> user;

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    string command, id, name;

    stringstream ss;

    for (int i = 0; i < record.size(); i++)
    {
        ss.str(record[i]);
        ss >> command;
        ss >> id;
        ss >> name;
        if (command == "Enter" || command == "Change") 
            user[id] = name;
        ss.clear();
    }

    for (int i = 0; i < record.size(); i++)
    {
        ss.str(record[i]);
        ss >> command;
        ss >> id;

        if (command == "Enter")
            answer.push_back(user[id] + "님이 들어왔습니다.");

        else if (command == "Leave")
            answer.push_back(user[id] + "님이 나갔습니다.");

        ss.clear();
    }
    return answer;
}
