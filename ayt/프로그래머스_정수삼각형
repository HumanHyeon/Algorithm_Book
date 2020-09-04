#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 500

using namespace std;

vector<vector<int>> triangle;
int cache[500][500];

int move(int a,int b){
    if(a==triangle.size()-1) return triangle[a][b];
    
    int& ret = cache[a][b];
    if(ret != -1) return ret;
    return ret = max(move(a+1,b),move(a+1,b+1)) + triangle[a][b];
}

int solution(vector<vector<int>> tmpTriangle) {
    triangle.assign(tmpTriangle.begin(), tmpTriangle.end());
    
    for(int i=0;i<MAX;++i)
        memset(cache[i], -1, sizeof(int)*MAX);
    
    int answer = move(0,0);
    
    return answer;
}
