#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    while (s!="1") {
        string tempStr = "";
        int notZero = 0;
        for(int i=0;i<s.length(); i++)
            if ( s[i] == '1' )
                notZero++;
        
        answer[1]+=s.length()-notZero;
        
        while(notZero!=0) {
            string r = to_string(notZero % 2);
            tempStr = r + tempStr;
            notZero/=2;
        }
        s=tempStr;
        answer[0]++;
    }
    return answer;
}
