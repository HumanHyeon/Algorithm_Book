#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//풀지못함 (참고)

// skill_trees_len은 skill_trees의 길이입니다.
int solution(char* skill, char* skill_trees[], size_t skill_trees_len)
{
    int answer = 0, k;
    for (int i = 0; i < skill_trees_len; i++)
    {
        k = 0;
        for (int j = 0; j < strlen(skill_trees[i]); j++)
        {
            if (strchr(skill, skill_trees[i][j]))
            {
                if (skill[k] == skill_trees[i][j])
                    k++;
                else
                    break;
            }

            if (j == strlen(skill_trees[i]) - 1)
            {
                answer++;
                printf("%s\n", skill_trees[i]);
            }
        }
    }
    return answer;
}