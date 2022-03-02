#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i = 0;i < n; i++) {
        if(i%2==0)
            answer.append("수");
        else
            answer.append("박");
    }
    
    return answer;
}
