#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    string tmp;
    bool tf = true;

    for (int i = 0; i < skill_trees.size(); ++i) {
        for (int j = 0; j < skill_trees[i].size(); ++j) 
            for (int z = 0; z < skill.size(); ++z) 
                if (skill[z] == skill_trees[i][j])
                    tmp += skill_trees[i][j];   
        
        for(int j=0;j<tmp.size();++j)
            if(tmp[j]!=skill[j]){
                tf = false;
                break;
            }
        
        if(tf)
            ++answer;
        
        tmp.clear();
        tf = true;
    }
    

    return answer;
}
