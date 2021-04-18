#include <vector>
using namespace std;

bool dfs(int cur, vector<vector<int>>& computers)
{
    int index;

    if (!computers[cur][cur])
        return (false);
    computers[cur][cur] = 0;
    index = 0;
    while (index < computers.size())
    {
        if (computers[cur][index])
            dfs(index, computers);
        index++;
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int i;

    i = 0;
    while (i < n)
    {
        if (computers[i][i])
            if (dfs(i, computers))
                answer++;
        i++;
    }
    return (answer);
}
