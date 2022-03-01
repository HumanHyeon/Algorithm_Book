#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<string, int> tb;
    map<string, int>::iterator it;
    
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            str += s[i];
        else {
            it = tb.find(str);
            if (it != tb.end())
                (it->second)++;
            else if (str != "")
                tb.insert(pair<string, int>(str, 1));
            str = "";
        }
    }
    
    vector<pair<string, int>> tmp;
    for (it = tb.begin(); it != tb.end(); it++) 
        tmp.push_back(*it);
    
    sort(tmp.begin(), tmp.end(), compare);
    
    for (int i = 0; i < tmp.size(); i++)
        answer.push_back(stoi(tmp[i].first));
    return answer;
}
