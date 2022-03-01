#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> wordboard;
    vector<string> a = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    int count = 1, current_num = 27;
    
    for(int i = 0; i < 26; i++)
        wordboard.insert(make_pair(a[i], i + 1));
    while(1)
    {
        string current = msg.substr(0, count);
        string next = msg.substr(count, 1);
        string wc = current + next;
        auto tmp_current = wordboard.find(current);
        auto tmp_next = wordboard.find(next);
        auto tmp_wc = wordboard.find(wc);
        
        if(tmp_current != wordboard.end())
        {
            if(tmp_wc != wordboard.end())
            {
                if(count < msg.size())
                    count++;
            }
            else
            {    
                answer.push_back(tmp_current->second);
                wordboard.insert(make_pair(wc, current_num++));
                msg.erase(0, count);
                count = 1;
            }
        }
        if(next == "\0")
        {
            answer.push_back(tmp_current->second);
            break;
        }
    }
    return answer;
}