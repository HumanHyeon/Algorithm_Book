#include <string>
#include <vector>
#include <cmath>

using namespace std;

int powI(int n, int exp) { return (int)pow((double)n, (double)exp); }

string intToBin(int n, vector<int> arr) {
    string result = "";
    for(int i = 0; i < arr.size(); i++)
        for(int j = n - 1; j >= 0; j--) {
            int temp = powI(2, j);
            if (arr[i] / temp > 0) {
                result += "1";
                arr[i] -= temp;
            }
            else result += "0";
        }
    
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) answer.push_back("");
    string arr1dec = intToBin(n, arr1);
    string arr2dec = intToBin(n, arr2);
    for(int i = 0; i < arr1dec.size(); i++) {
        string temp = "";
        if(arr1dec[i] == '0' && arr2dec[i] == '0')
            temp = " ";
        else
            temp = "#";
        answer[i / n] += temp;
    }
    
    return answer;
}
