#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    std::sort(participant.begin(), participant.end());
    std::sort(completion.begin(), completion.end());

    int num = 0;

    for(int i=0; i < participant.size(); i++){
        if( participant[i] != completion[i]){
            return participant[i];
        }
    }

    return participant[participant.size()-1];
}
