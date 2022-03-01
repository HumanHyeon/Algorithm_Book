#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        string tmp;
        arr1[i] = arr1[i] | arr2[i];
        while (arr1[i] > 0) {
            arr1[i] % 2 ? tmp = '#' + tmp : tmp = ' ' + tmp;
            arr1[i] /= 2;
        }
        while (tmp.size() != n) tmp = ' ' + tmp;
        answer.push_back(tmp);
    }

    return answer;
}
