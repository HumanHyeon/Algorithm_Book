#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tri(n);
    int checkpoint = n, flag = 0;   //flag -> 0: 하, 1:우, 2: 상
    int level = 0, width = 0, check = 0, insertCnt = 1;

    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        switch (flag)
        {
        case 0:
            tri[level].insert(tri[level].begin() + width, i);
            level++;
            break;
        case 1:
            tri[level].insert(tri[level].begin() + width + insertCnt++, i);
            break;
        case 2:
            tri[level].insert(tri[level].end() - width, i);
            level--;
            break;
        default:
            break;
        }

        check++;
        if (check == checkpoint) {
            checkpoint--;
            check = 0;
            if (flag == 2) flag = 0, width++;
            else flag++;   

            if (flag == 0)    level += 2;
            else if (flag == 1) level--, insertCnt = 1;
            else if (flag == 2)   level--;
        }
    }

    for (auto tmp : tri) 
        for (auto insert : tmp) 
            answer.push_back(insert);

    return answer;
}
