#include <vector>
#include <iostream>
using namespace std;

int answer2 = 0;

void findPrime(int n) {
    bool ck = true;

    if (n == 0 || n == 1) return;
    if (n == 2) {
        ++answer2;
        return;
    }
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            ck = false;
            break;
        }
    }
    if (ck)
        ++answer2;
}

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                sum = nums[i] + nums[j] + nums[k];
                findPrime(sum);
                sum = 0;
            }
        }
    }

    answer = answer2;

    return answer;
}
