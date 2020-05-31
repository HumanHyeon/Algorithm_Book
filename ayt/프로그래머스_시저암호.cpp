#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0;i < s.size();i++) {
        if(n == 0) break;
        else if(s[i] == ' ') continue;
        else
            for(int j = 0;j < n;j++) {
                if(s[i] == 90 || s[i] == 122)
                    s[i] -= 26;
                s[i]++;
            }
    }
    answer = s;
    
    return answer;
}
