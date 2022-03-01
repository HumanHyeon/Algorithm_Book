#include <vector>
#include <algorithm>
using namespace std;

string step1(string s) {
    string rs = "";
    int count = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == '1') count++;
    for (int i = 0; i < count; i++) rs += "1"; 
    return rs;
}

string step2(int n) {
    string bin = "";
    for (int i = n; i >= 1; i /= 2) 
        if (i % 2 == 1)  bin += "1";
        else bin += "0";
    reverse(bin.begin(), bin.end());
    return bin;
}

vector<int> solution(string s) {
    int removeZero = 0, cycle = 0;
    while (true) {
        if (s == "1") break;
        string afterS1 = step1(s);
        removeZero += s.size() - afterS1.size();
        s = step2(afterS1.size());
        cycle++;
    }
    return { cycle, removeZero };
}
