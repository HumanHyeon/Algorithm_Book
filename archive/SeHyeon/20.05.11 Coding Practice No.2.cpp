#include <iostream>
#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
  
    for (int i = 0; i < n; i++) 
        if (i % 2)   answer += "박";
        else answer += "수";

    return answer;
}

int main() {
    cout << solution(4) << endl;
}

//#1
//for (int i = 0; i < n; i++)
//    i & 1 ? answer += "박" : answer += "수";

//#2
//for (int i = 0; i < n / 2; i++) {
//    answer.append("수박");
//}
//if (n % 2 == 1)
//answer.append("수");
