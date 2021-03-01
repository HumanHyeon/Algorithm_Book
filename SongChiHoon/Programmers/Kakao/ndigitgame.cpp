#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";

    string temp = "";
    int present_number = 0;
    int current_number = 0;
    int remainder = 0;
    int ordercounter = 0;

    while (true) {
        current_number = present_number / n;
        while( current_number == 0) {
            remainder = present_number % n;

            // 숫자를 글자로 변환해서 넣어두기

        }

        if(ordercounter % m == p - 1) {
            answer.append(temp[]);
        }
        if(answer.length() == t) {
            break;
        }
        else {
            ordercounter++;
            present_number++;
        }
    }
    return answer;
}