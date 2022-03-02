#include <string>
#include <vector>

using namespace std;

int findIndex(vector<string>& dict, string w) {
    for (int i = 1; i < dict.size(); i++)
        if (dict[i] == w) return i;
    return 0;
}


vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dict;
    
    // 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    dict.push_back("-");    //push nullstring at index 0
    for (char i = 'A'; i <= 'Z'; i++) {
        dict.push_back("-");    //push nullstring at index i
        dict[1 + i - 'A'][0] = i;
    }
    
    while (msg.length() > 0) {
        int index;
        // 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        string w = msg.substr(0, 1);
        index = findIndex(dict, w);        //0 = fail, others = index
        while (w.length() < msg.length()) {
            string temp = msg.substr(0, w.length()+1);
            int tempIndex = findIndex(dict, temp);
            if (tempIndex != 0) {  //if find
                w = temp;
                index = tempIndex;
            }
            else    //fail
                break;
        }
        // 3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
        answer.push_back(index);
        msg = msg.substr(w.length(), msg.length() - w.length());
        // 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        if (msg.length() > 0)
            dict.push_back(w+msg.substr(0, 1));
    }
    
    return answer;
}
