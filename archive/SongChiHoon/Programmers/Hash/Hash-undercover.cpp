#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothesboard;
    string temp;
    for(int i = 0; i < clothes.size(); i++) {
        temp = clothes[i][1];
        clothesboard[temp] += 1;
    }
    map<string, int>::iterator it;
    for(it = clothesboard.begin(); it != clothesboard.end(); it++) {
        answer = answer * (it->second + 1);
    }
    answer -= 1;
    return answer;
}