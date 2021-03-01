#include <string>
#include <vector>

#include <iostream>

using namespace std;

void getProperties(string data, int type, string* properties) {
    int propIndex = 0;
    //init
    for (int i = 0; i < 5; i++)
        properties[i] = "";
    
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == ' ' && type == 0) { // type: info
            propIndex++; continue;
        }
        if (data[i] == ' ' && type == 1) { // type: query
            if (propIndex != 3)
                i += 4;
            propIndex++; continue;
        }
        properties[propIndex] += data[i];
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string properties_query[5];
    string infoTable[50000][5];
    
    //Make prototype of infoTable
    for (int i = 0; i < info.size(); i++)
        getProperties(info[i], 0, &infoTable[i][0]);
    
    //Search All query
    for (int i = 0; i < query.size(); i++) {
        int queryResult = 0;
        getProperties(query[i], 1, &properties_query[0]);
        //Search infoTable
        for (int j = 0; j < info.size(); j++) {
            if (properties_query[0] != "-" && properties_query[0] != infoTable[j][0]) continue;
            if (properties_query[1] != "-" && properties_query[1] != infoTable[j][1]) continue;
            if (properties_query[2] != "-" && properties_query[2] != infoTable[j][2]) continue;
            if (properties_query[3] != "-" && properties_query[3] != infoTable[j][3]) continue;
            if (stoi(properties_query[4]) > stoi(infoTable[j][4])) continue;
            
            //find
            queryResult++;
        }
        answer.push_back(queryResult);
    }
    
    return answer;
}
