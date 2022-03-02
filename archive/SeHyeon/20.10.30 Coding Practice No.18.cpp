#include <map>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> skillTable;

    for (int i = 0; i < skill.size(); i++)
        skillTable[skill[i]] = i;

    for (int i = 0; i < skill_trees.size(); i++) {
        bool flag = true;
        int learn = 0;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (skillTable.find(skill_trees[i][j]) == skillTable.end())  continue;
            if (learn < skillTable.find(skill_trees[i][j])->second) {
                flag = false;
                break;
            }
            learn++;
        }
        if (flag) answer++;
    }

    return answer;
}
