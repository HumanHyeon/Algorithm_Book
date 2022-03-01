#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int r;

    while (n > 0) {
        r = n % 3;
        if (r == 0) {
            answer.push_back('4');
            n = n/3 - 1;
        }
        else if (r == 1) {
            answer.push_back('1');
            n /= 3;
        }
        else {
            answer.push_back('2');
            n /= 3;
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}
