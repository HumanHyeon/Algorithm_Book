#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string order, vector<string> skill_trees) {
    int answer = 0;
    int count;

    for (string skill_tree : skill_trees) {
        //각 testcase에 대해 수행
        for (int i = 0; i < skill_tree.size(); i++) {
            for (count = 0; count < order.size(); count++) 
                if (skill_tree[i] == order[count]) break;
            if (count == order.size())  //일치하는 값이 없다면
                skill_tree.erase(skill_tree.begin() + i--);
        }
        if (!order.compare(0, skill_tree.length(), skill_tree)) answer++;
    }
    return answer;
}

 int main(void) {
    int result = solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" }); //expected result = 2
    cout << result;

    return 0;
}
