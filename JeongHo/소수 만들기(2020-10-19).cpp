#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <cmath>

int solution(int nums[], size_t nums_len)
{
    int answer = 0;
    for (int i = 0; i < nums_len; i++)
    {
        for (int j = i + 1; j < nums_len; j++)
        {
            for (int k = j + 1; k < nums_len; k++)
            {
                bool flag = true;
                for (int x = 2; x <= sqrt(nums[i] + nums[j] + nums[k]); x++)
                {
                    if ((nums[i] + nums[j] + nums[k]) % x == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag) answer++;
            }
        }
    }

    return answer;
}