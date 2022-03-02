#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    string temp;
    string tempboard;
    int startpoint = 0;
    for (int i = 0; i < n; i++) {
        bitset<16> temp1 = arr1[i];
        bitset<16> temp2 = arr2[i];
        bitset<16> temp_bit = temp1 | temp2;

        temp = temp_bit.to_string();
        tempboard = "";
        startpoint = 16-n;
        for (int j = startpoint; j < 16; j++) {
            temp[j] == '1' ? tempboard += '#' : tempboard += " ";
        }
        answer.push_back(tempboard);
    }
    return answer;
}