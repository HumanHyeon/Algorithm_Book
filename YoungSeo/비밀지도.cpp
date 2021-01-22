#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string line = "";
 
    for (int i = 0; i < n; i++) {
        line = bitset<16>(arr1[i] | arr2[i]).to_string();
        for (int j = 16 - n; j < 16; j++) {
            if (line[j] == '1') line[j] = '#';
            else line[j] = ' ';
        }
        answer.push_back(line.substr(16-n, 16)); line = "";
    }
    return answer;
}
