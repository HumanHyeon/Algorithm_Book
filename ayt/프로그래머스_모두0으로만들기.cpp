#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

long long answer = 0;

bool promising(vector<long> a) {
    long long sum = 0;
    for(auto elem : a)
        sum += elem;
    if(!sum) return true;
    else return false;
}

void dfs(vector<vector<long long>>& t, vector<long>& a, int now, int parent) {
    for(int i=0;i<t[now].size();++i) {
        if(t[now][i] != parent)
            dfs(t,a,t[now][i],now);
    }
    a[parent] += a[now];
    answer += abs(a[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<vector<long long>> t;
    vector<long> a2(a.size());
    
    for(int i=0;i<a.size();++i) a2[i]=a[i];
    
    if(!promising(a2)) return -1;
    
    for(int i=0;i<a2.size();i++){
        vector<long long> tmp;
        t.push_back(tmp);
    }
    
    for(int i=0;i<edges.size();i++) {
        t[edges[i][0]].push_back(edges[i][1]);
        t[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(t,a2,0,0);
    
    return answer;
}
