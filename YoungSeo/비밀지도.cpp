#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string s3 = "";
 
    for (int i = 0; i < n; i++) {
        s3 = bitset<16>(arr1[i] | arr2[i]).to_string();
        for (int j = 16 - n; j < 16; j++) {
            if (s3[j] == '1') s3[j] = '#';
            else s3[j] = ' ';
        }
        answer.push_back(s3.substr(16-n, 16)); 
    }
    return answer;
}
