#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int numbers[3] = {4, 1, 2};
    while(n > 0) {
        answer = to_string(numbers[n%3]) + answer;
        if(!(n%3)) {
            n = n/3 - 1;
        }
        else {
            n = n/3;
        }
    }
    return answer;
}

// string solution(int n) {
//     string answer = "";
//     int numbers[3] = {1, 2, 4};
//     int temp;
//     while(n>0) {
//         n-=1;
//         temp = n%3;
//         answer = to_string(numbers[temp]) + answer;
//         n /= 3;
//     }
//     return answer;
// }