#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sumnum = brown + yellow;
    for(int i = 1; i < sumnum; i++) {
        if(sumnum % i == 0 && sumnum / i <= i && yellow % (i-2) == 0) {
            answer.push_back(i);
            answer.push_back(sumnum / i);
            break;
        }
    }
    return answer;
}