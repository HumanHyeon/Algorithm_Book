#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> di;
string apb = "AEIOU";

void add(string a) {
    if (a.size() == 5) return;

    for (int i = 0; i < 5; i++) {
        di.push_back(a+apb[i]);
        add(a + apb[i]);
    }
}

int solution(string word) {
    int answer = 0;

    add("");

    for (int i = 0; i < di.size(); i++) {
        if (word == di[i]) {
            answer = ++i;
            break;
        }
    }

    return answer;
}
