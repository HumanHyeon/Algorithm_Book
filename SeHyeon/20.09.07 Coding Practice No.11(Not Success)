#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> us;
    for (vector<string>::iterator iter = completion.begin(); iter != completion.end(); iter++)
        us.insert(*iter);
    for (vector<string>::iterator iter = participant.begin(); iter != participant.end(); iter++) {
        unordered_multiset<string>::iterator siter = us.find(*iter);
        if (siter == us.end())  return *iter;
    }  
    return "";
}
