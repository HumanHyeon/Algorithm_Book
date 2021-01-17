#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> table;
    for (int i = 0, count = 1; i < words.size(); i++, count++) {
        if (table.find(words[i]) != table.end()) return { count % n == 0 ? n : count % n, (int)ceil((double)count / n) };
        if (i != 0 && words[i - 1][words[i - 1].size() - 1] != words[i][0])  return { count % n == 0 ? n : count % n, (int)ceil((double)count / n) };
        table.insert(words[i]);
    }
    return { 0, 0 };
}
