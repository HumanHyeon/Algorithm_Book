#include <string>
#include <vector>

using namespace std;

void findNQ(int n, int j, int& answer) {
    for(int i=0;i<n;i++) {
        if(a[i]==false && b[j+i]==false && c[j-i+n-1]==false) {
            pos[j]=i;
            if(j==n-1) 
                ++answer;
            else {
                a[j]=b[j+i]=c[j-i+n-1]=true;
                findNQ(n,j+1,answer);
                a[j]=b[j+i]=c[j-i+n-1]=false;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    static bool *a = new bool[n];
    static bool *b = new bool[n];
    static bool *c = new bool[n];
    static int *pos = new int[n];
    
    findNQ(n,0,answer);
    
    return answer;
}
