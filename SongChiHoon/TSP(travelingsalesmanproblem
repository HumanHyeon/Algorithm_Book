#include <iostream>
#include <vector>
using namespace std;

int n;
double MAX, INF;
double dist[MAX][MAX];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
    if(path.size() == n)
        return currentLength + dist[path[0]][path.back()];
    double ret = INF;

    for(int next = 0; next <n; ++next)
    {
        if(visited[next])
            continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
        return ret;
}

int main() 
{
    int C, pinpoint;
    
    printf("케이스 수를 입력하시오 :");
    cin >> C;
    printf("목적지 갯수를 입력하시오 :");
    cin >> pinpoint;

    for(int i = 0; i < C; i++)
    {
        printf("%d", shortestPath(pinpoint));
    }

    return;
}
