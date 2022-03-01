#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isprime(int target) {
    for(int i = 2; i <= sqrt(target); i++) {
        if(target % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    int temp;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++) {
        for(int j = i+1; j < nums.size() - 1; j++) {
            for(int k = j+1; k < nums.size(); k++) {
                temp = nums[i] + nums[j] + nums[k];
                if(isprime(temp)) {
                    answer++;
                }
            }
        }
    }

    return answer;
}