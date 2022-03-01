#include <string>
#include <iostream>

using namespace std;

//split함수, pos2가 out of bound 이면 그이상 return하지 않음
string splitString(string str, int pos1, int pos2) {
    string result = "";
    for (int i = pos1; i <= pos2; i++)
        if (i >= str.length()) break;
        else result += str[i];

    return result;
}

int solution(string s) {
    int shortestLength = 9999;
    // 1글자씩 압축 ~ s.length()-2 글자씩 압축
    for (int bytes = 1; bytes <= s.length() / 2 + 1; bytes++) {
        string resultStr = "";

        int count = 1;
        int pos1 = 0, pos2 = bytes - 1;

        string token = splitString(s, pos1, pos2);
        while (true) {
            pos1 += bytes;
            pos2 += bytes;
            //다음 cmpStr이 만들어질수 없다면 종료 (index out of bound exception)
            if (pos1 > s.length() - 1) {
                if (count > 1) resultStr += to_string(count);
                resultStr += token;
                break;
            }

            //비교할 cmpStr 생성
            string cmpStr = splitString(s, pos1, pos2);
            if (token == cmpStr) count++;
            else {
                if (count > 1) resultStr += to_string(count);
                resultStr += token;
                token = cmpStr;
                count = 1;
            }

        }
        if (resultStr.length() < shortestLength)
            shortestLength = resultStr.length();
        //결과확인
        //cout << s << ", bytes: " << bytes << ", resultStr:" << resultStr << endl;
    }
    return shortestLength;
}

int main(void) {
    const int SIZE = 6;
    string testcase[SIZE] = { 
        "aabbaccc", 
        "ababcdcdababcdcd", 
        "abcabcdede", 
        "abcabcabcabcdededededede", 
        "xababcdcdababcdcd",
        "aaaaaaaaaa"
    };
    
    for (int i = 0; i < SIZE; i++)
        cout << solution(testcase[i]) << endl;
}
