https://programmers.co.kr/learn/courses/30/lessons/12915

#include <vector>
#include <algorithm>
using namespace std;

int standard;

bool cmp(string& a, string& b) {
    if (a[standard] == b[standard]) return a < b;
    else return a[standard] < b[standard];
}

vector<string> solution(vector<string> strings, int n) {
    standard = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}
