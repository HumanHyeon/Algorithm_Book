//https://programmers.co.kr/learn/courses/30/lessons/12977#
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    int sum = 0;

    vector<int>sums;

    for (int a = 0; a < nums.size(); a++)
    {
        for (int b = a + 1; b < nums.size(); b++)
        {
            for (int c = b + 1; c < nums.size(); c++)
            {
                bool overlap = false;

                sum = (nums[a] + nums[b] + nums[c]);

                sums.push_back(sum);
            }
        }
    }

    for (int i = 0; i < sums.size(); i++)
    {
        bool chk_prime = false;

        for (int j = 2; j <= sqrt(sums[i]); j++)
        {
            if ((sums[i] % j) == 0)
            { 
                chk_prime = true;
                break;
            }
        }

        if (!chk_prime)
            answer++;
    }

    return answer;
}
