#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> hashmap;
    for (int i = 0; i < participant.size(); i++) {
        hashmap[participant[i]] += 1;
    }
    for (int i = 0; i < completion.size(); i++) {
        hashmap[completion[i]] -= 1;
    }
    for (int i = 0; i < participant.size(); ++i) {
    	if (hashmap[participant[i]] != 0) {
            answer = participant[i];
        }
    }
    return answer;
}