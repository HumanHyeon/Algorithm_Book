#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct song
{
    int time;
    string name;
    string code;
    bool answer = false;
};

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    song *list = new song[musicinfos.size()];

    string nowm = "";
    for(int i = 0; i < m.size(); i++) {
        if(m[i+1] == '#'){
            nowm += tolower(m[i]);
            i++;
        }
        else {
            nowm += m[i];
        }
    }
    string temp;

    for(int i = 0; i < musicinfos.size(); i++){
        temp = "";

        int starthour = stoi(musicinfos[i].substr(0, 2));
        int endhour = stoi(musicinfos[i].substr(6, 2));
        int startmin = stoi(musicinfos[i].substr(3, 2));
        int endmin = stoi(musicinfos[i].substr(9, 2));

        list[i].time = (endhour - starthour) * 60 + (endmin - startmin);
        int current = musicinfos[i].std::string::find(",",6)+1;
        int namelast = musicinfos[i].std::string::find(",",12);
        int namelength = namelast - current;
        list[i].name = musicinfos[i].substr(musicinfos[i].std::string::find(",",6)+1, namelength);
        list[i].code = musicinfos[i].substr(musicinfos[i].std::string::find(",",12)+1);

        int cycle = list[i].time;

        for(int j = 0; j < cycle; j++){
            if(list[i].code[(j%list[i].code.size())+1] == '#'){
                temp += tolower(list[i].code[j % list[i].code.size()]);
                j++;
                cycle++;
            }
            else {
                temp += list[i].code[j % list[i].code.size()];
            }
        }
        list[i].code = temp;

        if(list[i].code.find(nowm) != string::npos) {
            list[i].answer = true;
        }

    }
    int maxtime = 0;
    int answerindex = 0;

    for (int i = 0; i < musicinfos.size(); i++){
        if(list[i].time > maxtime && list[i].answer == true) {
            maxtime = list[i].time;
            answerindex = i;
            answer = list[answerindex].name;
        }
    }

    return answer;
}