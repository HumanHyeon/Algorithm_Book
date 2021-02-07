#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

map<string, vector<int>> table;

vector<int> solution(vector<string> paraInfo, vector<string> paraQuery) {
    vector<int> answer;

    for(auto info : paraInfo) {
        string infoList[4][2] = { { "-", }, { "-", }, { "-", }, { "-", } };
        int infoScore;
        istringstream iss(info);
        iss >> infoList[0][1] >> infoList[1][1] >> infoList[2][1] >> infoList[3][1] >> infoScore;
        
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++) 
                    for (int l = 0; l < 2; l++) {
                        string key = infoList[0][i] + infoList[1][j] + infoList[2][k] + infoList[3][l];
                        table[key].push_back(infoScore);
                    }
    }
    for (auto& fetch : table)    sort(fetch.second.begin(), fetch.second.end());

    for (auto query : paraQuery) {
        string key = "", list;
        int queryScore;
        stringstream ss(query);
        
        while (ss >> list) 
            if (list == "and")   continue;
            else if (ss.eof()) queryScore = stoi(list);
            else key += list;

        vector<int> scoreList = table[key];
        answer.push_back(scoreList.end() - lower_bound(scoreList.begin(), scoreList.end(), queryScore));
    }

    return answer;
}
