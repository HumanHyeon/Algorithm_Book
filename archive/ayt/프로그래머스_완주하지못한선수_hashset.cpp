#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_multiset<string> hashset;
    
    for(auto alem : participant ){
        hashset.insert(alem);
    }
    for(auto alem : completion){
        hashset.erase(hashset.find(alem));
    }
    
    answer = *hashset.begin();
    
    return answer;
}
