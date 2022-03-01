#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string ret = "";

    string temp = "";
    char c;
    for(int i = 0 ; i < new_id.size(); i++) {
        if (new_id[i] > 'A' && new_id[i] < 'Z') {
            c = new_id[i];
            temp += tolower(c);
        }
        else {
            c = new_id[i];
            temp += c;
        }
    }

    for(int i = 0 ; i < temp.size(); i++) {
        if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= '0' && temp[i] <= '9')) {
            ret += temp[i];
        }
        if((temp[i] == '-') || (temp[i] == '.') || (temp[i] == '_')) {
            ret += temp[i];
        }
    }
    cout << ret << endl;

    temp = "";
    for (int point = 0; point < ret.size(); point++) {
        if(point == ret.size()) {
            temp += ret.back();
            break;
        }
        if(ret[point] == '.' && ret[point+1] == '.') {
            temp += '.';
            point += 1;
        }
        else {
            temp += ret[point];
        }
    }

    if(temp.front() == ".") {

    }

    cout << temp;
    
    return answer;
}