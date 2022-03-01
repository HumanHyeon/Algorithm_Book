#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int playTime = 0;
    
    for (int i = 0; i < musicinfos.size(); i++) {
        bool isCorrect = false;
        
        string properties[4];   //startTime, endTime, title, contents
        int count = 0;
        
        int noteCounts;      //endTime - startTime
        string realContents;    //contents: (noteCounts/contents.length()) times repeat
        int strPointer;
        
        //init
        for (int j = 0; j < 4; j++)
            properties[j] = "";
        
        //split
        for (int j = 0; j < musicinfos[i].length(); j++) {
            if (musicinfos[i][j] == ',') { 
                count++;
                continue;
            }
            properties[count] += musicinfos[i][j];
        }
        
        //endTime(properties[1]) - startTime(properties[0])
        noteCounts = 600 * ((int)properties[1][0] - (int)properties[0][0]) + 
                     60 * ((int)properties[1][1] - (int)properties[0][1]) + 
                     10 * ((int)properties[1][3] - (int)properties[0][3]) + 
                     ((int)properties[1][4] - (int)properties[0][4]);
        
        //make realContents
        strPointer = 0;
        for (int j = 0; j < noteCounts; j++) {
            realContents += properties[3][strPointer++];
            if (strPointer == properties[3].length())   //out of bound
                strPointer = 0;
            if (properties[3][strPointer] == '#') {     //if #  ->  add #
                realContents += '#';
                strPointer++;
            }
            if (strPointer == properties[3].length())   //out of bound 2
                strPointer = 0;
        }
        
        //find m in realContents
        for (int j = 0; j < realContents.length(); j++) {
            if (m[0] != realContents[j])
                continue;
            if (j + m.length() - 1 >= realContents.length())
                break;
            if (realContents.substr(j, m.length()) == m)
                if (j + m.length() == realContents.length())
                    isCorrect = true;
                else if (realContents[j + m.length()] != '#')
                    isCorrect = true;
        }
        
        if (isCorrect && playTime < noteCounts) {
            answer = properties[2];
            playTime = noteCounts;
        }
    }
    
    return answer;
}
