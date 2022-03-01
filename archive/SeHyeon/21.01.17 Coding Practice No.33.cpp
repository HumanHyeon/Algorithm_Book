#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        bitset<16> bs1 = arr1[i], bs2 = arr2[i];
        string input = "", tmp;
        
        bs1 = bs1 | bs2;
        tmp = bs1.to_string();
        for (int j = 16 - n; j < 16; j++)   input += (tmp[j] == '1' ? '#' : ' ');
        answer.push_back(input);
    }
    return answer;
}
