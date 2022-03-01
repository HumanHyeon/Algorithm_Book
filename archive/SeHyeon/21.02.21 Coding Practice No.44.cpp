#include <iostream>
#include <string>
#include <vector>
#define ASCII(n) (n <= 9 ? '0' + n : 'A' + n - 10)
#define NUM(n) (n <= '9' ? n - '0' : n - 'A' + 10)
using namespace std;

void roundUp(string& input, const int n) {
    for (int i = input.size() - 1; i > 0; i--) {
        if (NUM(input[i]) == n) {
            input[i - 1] = ASCII(NUM(input[i - 1]) + 1);
            input[i] = '0';
        }
        else return;
    }
    if (NUM(input[0]) == n) {
        input[0] = '0';
        input.insert(0, "1");
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "", record = "";
    int number = 0, turn = 1;
    for (; answer.size() < t;) {
        if (record.size() == 0) {   //비어있으면
            if (number == n) {      //n진법에 다다르면
                number = 0, record = "10";
            }
            else {                  //n진법에 다다르지 않음
                if (turn == p)  answer += ASCII(number);
                turn == m ? turn = 1 : turn++;   
                number++;
            }
        }
        else {
            if (number == n) {
                record[record.size() - 1] = ASCII(number);
                roundUp(record, n); number = 1;
            }
            else {
                record[record.size() - 1] = ASCII(number);
                number++;
            }

            for (int i = 0; i < record.size(); i++) {
                if (turn == p)  answer += record[i];
                turn == m ? turn = 1 : turn++;
                if (answer.size() == t) return answer;
                
            }
        }
    }

    return answer;
}
