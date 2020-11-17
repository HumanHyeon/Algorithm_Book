//https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    vector<string> possible;

    string possible_skill;

    vector<char> core_skill;

    vector<string> user_skills;

    for (int i = 0; i < skill.size(); i++)
    {
        core_skill.push_back(skill[i]);

        possible_skill += skill[i];

        possible.push_back(possible_skill);
    }

    for (int i = 0; i < skill_trees.size(); i++)
    {
        bool contain = false;

        string user_skill = "";

        for (int j = 0; j < skill_trees[i].size(); j++)
            for (int a = 0; a < core_skill.size(); a++)
                if (core_skill[a] == skill_trees[i][j])
                {
                    user_skill += skill_trees[i][j];
                    contain = true;
                }

        if (!contain)
            answer++;
        else
            for (int j = 0; j < possible.size(); j++)
                if (possible[j] == user_skill)
                    answer++;

        contain = false;
    }

    return answer;
}
