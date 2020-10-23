#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    int temp;

    sort(nums.begin(), nums.end());

    int biggest = nums.back() * nums.back();
    for (int i = biggest; i > 0; i--) {
    	for (int index = nums.size(); index > 0; index--) {
    		temp += nums[index];
    		if(temp > i || temp < i) {
    			continue;
    		}
    		else {
    			answer++;
    		}
    	}
    }

    return answer;
}