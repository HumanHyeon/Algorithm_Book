#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> table;

    for (auto distribute : clothes)     table[distribute[1]]++;
    for (auto iter = table.begin(); iter != table.end(); iter++)    answer *= iter->second + 1;

    return --answer;
}
