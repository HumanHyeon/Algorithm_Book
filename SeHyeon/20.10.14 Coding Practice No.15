#include <vector>

bool isDecimal(int num) {
    if (num < 2)    return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)    return false;
    return true;
}

int solution(std::vector<int> nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) 
        for (int j = i + 1; j < nums.size(); j++) 
            for (int k = j + 1; k < nums.size(); k++) 
                if(isDecimal(nums[i] + nums[j] + nums[k]))   answer++;
    return answer;
}
