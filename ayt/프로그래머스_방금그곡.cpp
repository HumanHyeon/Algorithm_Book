#include <string>
#include <vector>

using namespace std;

int time(string mi) {
    int start = 60 * stoi(mi.substr(0, 2)) + stoi(mi.substr(3, 2));
    int end = 60 * stoi(mi.substr(6, 2)) + stoi(mi.substr(9, 2));
    if (end - start < 0) end += 24 * 60;
    return end - start;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int playtime = 0;

    for (int i = 0; i < m.size(); ++i) {
        if (m[i] == '#') { 
            m[i - 1] += 32; 
            m.erase(i, 1); 
        }
    }

    for (int i = 0; i < musicinfos.size(); ++i) {
        string mi = musicinfos[i];
        int min = time(mi);
        int idx = mi.find(",", 12);
        string name = mi.substr(12, idx - 12);
        string info = mi.substr(idx + 1);

        string tmp = "";
        int k = 0;
        for (int j = 0; j < min; ++j, ++k) {
            if (k == info.size()) k = 0;
            if (info[k] == '#') { tmp.back() += 32; --j; }
            else tmp += info[k];
        }
        if (info[k] == '#') tmp.back() += 32;

        if (string::npos != tmp.find(m) && min > playtime) {
            playtime = min;
            answer = name;
        }
    }

    return answer;
}

//ㅈ같은 문제
