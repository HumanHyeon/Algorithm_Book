#include <string>
#include <vector>
using namespace std;

void unionChar(string& input) {
    string result = "";
    for (int i = 0; i < input.size(); i++)
        if (i == input.size() - 1) result += input[i];
        else if (input[i + 1] == '#') result += tolower(input[i]), i++;
        else result += input[i];   
    input = result;
}

int subTime(string startTime, string endTime) {
    int startTimeHour = stoi(startTime.substr(0, 2)), endTimeHour = stoi(endTime.substr(0, 2));
    int startTimeMin = stoi(startTime.substr(3, 2)), endTimeMin = stoi(endTime.substr(3, 2));
    return (endTimeHour - startTimeHour) * 60 + (endTimeMin - startTimeMin);
}

string solution(string m, vector<string> musicinfos) {
    pair<int, string> answer = make_pair(-1, "(None)");

    unionChar(m);
    for (int i = 0; i < musicinfos.size(); i++) {
        string music = "", name = "", allMusic = "";
        int index, minute = subTime(musicinfos[i].substr(0, 5), musicinfos[i].substr(6, 5));
        if (answer.first >= minute)  continue;

        for (index = 12; musicinfos[i][index] != ','; index++)   name += musicinfos[i][index];
        for (index++; index < musicinfos[i].size(); index++) music += musicinfos[i][index];
        
        unionChar(music);
        while (true) {
            if (music.size() >= minute) {
                allMusic += music.substr(0, minute);
                break;
            }
            allMusic += music;
            minute -= music.size();
        }
        if (allMusic.find(m) != string::npos) answer = make_pair(allMusic.size(), name);
    }

    return answer.second;
}
