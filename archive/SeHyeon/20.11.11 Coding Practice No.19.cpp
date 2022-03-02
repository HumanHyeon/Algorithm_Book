#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int timeToInt(string time) {
    stringstream ss(time);
    string buffer;
    int result = 0;
    bool flag = true;

    while (getline(ss, buffer, ':')) {
        stringstream ssInt(buffer);
        int tmp;
        ssInt >> tmp;       //tmp = stoi(buffer);
        if (flag) tmp *= 100;
        result += tmp;
        flag = false;
    }
    return result;
}

string timeToString(int time) {
    string returnString = "";
    int hour = time / 100, min = time % 100;
    if (hour < 10)   returnString += "0";
    returnString += to_string(hour) + ":";
    if (min < 10)  returnString += "0";
    returnString += to_string(min);
    return returnString;
}

string calcNextBus(string standardTime, int t, int n = 2) {
    int calc = (n - 1) * t;
    int hour = calc / 60, min = calc % 60;
    int base = timeToInt(standardTime);
    int baseHour = base / 100, baseMin = base % 100;
    int result = baseMin + min;
    if (result >= 60)    baseHour++, result -= 60;
    result += (baseHour + hour) * 100;
    return timeToString(result);
}

int calcTime(string time, int num) {    //num must nuder 60
    int calc = timeToInt(time);
    int hour = calc / 100, min = calc % 100;
    min += num;
    if (min < 0)     hour--, min += 60;
    else if (min >= 60)  hour++, min -= 60;
    return (hour * 100) + min;
}

string solution(int n, int t, int m, vector<string> tt) {
    string answer = "";
    stable_sort(tt.begin(), tt.end());
    
    //case 2번
    answer = calcNextBus("09:00", t, n);
    if (timeToInt(answer) < timeToInt(tt[0])) return answer;

    //case 1번 - 첫차
    int count = 1, tmpN = n;
    for (int i = 0; i < tt.size(); i++) {
        if (timeToInt(tt[i]) <= 9000)    count++;
        else break;
        if (count > m) {
            if (tmpN == 1)  return timeToString(calcTime(tt[i], -1));
            else count -= m, tmpN--;
        }
        //lastTime = tt[i];
    }
    
    //case 3번 - 평범한 경우
    count = 1, tmpN = n;
    string time = "09:00";
    for (int i = 0; i < tt.size(); i++) {
        while (timeToInt(time) < timeToInt(tt[i])) {
            count = 1;
            tmpN--;
            time = calcNextBus(time, t);
        }
        count++;
        cout << timeToInt(time) << "\t" << timeToInt(tt[i]) << endl;
        
        if (count > m) {
            if (tmpN == 1) return timeToString(calcTime(tt[i], -1));
            else {
                count -= m, tmpN--;
                time = calcNextBus(time, t);
            }
        }
    }
    return answer;
}
