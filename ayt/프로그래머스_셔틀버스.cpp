#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string start = "09:00";
int hour = stoi(start.substr(0, 2));
int minu = stoi(start.substr(3));

void int_to_string() {
    if (!(hour / 10)) start.replace(0, 2, '0' + to_string(hour));
    else start.replace(0, 2, to_string(hour));

    if (!(minu / 10)) start.replace(3, 2, '0' + to_string(minu));
    else start.replace(3, 2, to_string(minu));
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<string>time = timetable;
    bool tf = false;

    sort(time.begin(), time.end(), greater<string>());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (time.empty() || time.back() >= "23:51") {
                tf = true;
                break;
            }
            else if (time.back() <= start) {
                time.pop_back();
            }
        }
        if (time.empty() || i == n - 1)
            break;

        minu += t % 60;
        hour += t / 60;

        int_to_string();
    }

    if(!tf) {
        if (stoi(timetable.front().substr(3)) == 0) {
            minu = 59;
            --hour;
        }
        else {
            hour = stoi(timetable.front().substr(0, 2));
            minu = stoi(timetable.front().substr(3)) - 1;
        }

        int_to_string();
    }

    answer = start;

    return answer;
}
