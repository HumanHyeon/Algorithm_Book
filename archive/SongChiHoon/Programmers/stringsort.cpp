#include <string>
#include <vector>
 
using namespace std;
 
vector<string> solution(vector<string> strings, int n) {
 
    for (int i = 0; i < strings.size(); i++) {
        for (int j = i+1; j <= strings.size()-1; j++) {
            if (strings[i][n]>strings[j][n]) {
                strings[i].swap(strings[j]);
            }
            else if (strings[i][n] == strings[j][n] && strings[i]>strings[j]) {
                strings[i].swap(strings[j]);
            }
        }
    }
    return strings;
}
