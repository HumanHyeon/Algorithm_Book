#include <vector>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> uidname;
    vector<pair<string, string>> uidname2;
    string tmp = "";
    string uid, name;

    for (int i = 0; i < record.size(); ++i) {
        for (int j = 0; j < record[i].size(); ++j) {
            tmp += record[i][j];
            if (tmp == "Enter " || tmp == "Change ") {
                tmp.clear();
                continue;
            }
            else if (tmp == "Leave ") {
                tmp.clear();
                break;
            }
            if (record[i][j] == ' ') {
                tmp.pop_back();
                uid = tmp;
                tmp.clear();
            }
        }
        if (!tmp.empty()) {
            name = tmp;
            uidname.push_back(make_pair(uid, name));
            tmp.clear();
        }
    }

    for (int i = 0; i < uidname.size(); ++i) {
        for (int j = i + 1; j < uidname.size(); ++j) {
            if (uidname[i].first == uidname[j].first) {
                uid = uidname[j].first;
                name = uidname[j].second;
                uidname2.push_back(make_pair(uid, name));
            }
        }
    }

    string ins;
    string res;
    for (int i = 0; i < record.size(); ++i) {
        for (int j = 0; j < record[i].size(); ++j) {
            tmp += record[i][j];
            if (tmp == "Enter " || tmp == "Leave ") {
                ins = tmp;
                tmp.clear();
                continue;
            }
            else if (tmp == "Change ") {
                tmp.clear();
                break;
            }
            if (record[i][j] == ' ') {
                tmp.pop_back();
                break;
            }
        }
        if (ins == "Enter ") {
            for (int j = 0; j < uidname2.size(); ++j) {
                if (uidname2[j].first == tmp) {
                    res = uidname2[j].second + "님이 들어왔습니다.";
                    answer.push_back(res);
                    break;
                }
            }
        }
        else if (ins == "Leave ") {
            for (int j = 0; j < uidname2.size(); ++j) {
                if (uidname2[j].first == tmp) {
                    res = uidname2[j].second + "님이 나갔습니다.";
                    answer.push_back(res);
                    break;
                }
            }
        }
        tmp.clear();
    }

    return answer;
}
