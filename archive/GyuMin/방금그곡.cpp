//https://programmers.co.kr/learn/courses/30/lessons/17683#qna
#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos)
{
    string answer = "";

    vector<string> pos_names;
    vector<int> pos_length;

    for (int i = 0; i < musicinfos.size(); i++)
    {
        int start_time = (stoi(musicinfos[i].substr(0, 2))) * 60 + stoi(musicinfos[i].substr(3, 2));
        int end_time = (stoi(musicinfos[i].substr(6, 2))) * 60 + stoi(musicinfos[i].substr(9, 2));
        string cutted = musicinfos[i].substr(12, musicinfos[i].size() - 12);

        int playtime = end_time - start_time;

        string song_name;
        string song_info;

        for (int j = 0;; j++)       
            if (cutted[j] == ',')
            {
                song_info = cutted.substr(j + 1, cutted.size() - j);
                break;
            }
            else
                song_name.push_back(cutted[j]);        

        string fix_s = song_info;

        song_info.clear();

        for (int a = 0; a < fix_s.size(); a++)
            if (fix_s[a] == '#')
                song_info[song_info.size() - 1] = tolower(song_info[song_info.size() - 1]);
            else
                song_info.push_back(fix_s[a]);

        song_info = song_info.substr(0, playtime);

        string fix_m = m;

        m.clear();

        for (int a = 0; a < fix_m.size(); a++)
            if (fix_m[a] == '#')
                m[m.size() - 1] = tolower(m[m.size() - 1]);
            else
                m.push_back(fix_m[a]);

        while (song_info.size() < playtime)
            song_info += song_info;

        string com;

        for (int j = 0; j < song_info.size(); j++)
        {
            if (song_info[j] == m[0])
            {
                int count = m.size();

                for (int a = 0; a < count; a++)              
                    com.push_back(song_info[j + a]);               
            }
            if (m == com)
            {
                pos_names.push_back(song_name);
                pos_length.push_back(playtime);
                break;
            }
            com.clear();
        }
    }

    int compare = 0;
    int ind = -1;

    for (int i = 0; i < pos_length.size(); i++)
        if (pos_length[i] > compare)
        {
            compare = pos_length[i];
            ind = i;
        }

    if (ind == -1)
        return "(None)";

    else
        return pos_names[ind];
}
