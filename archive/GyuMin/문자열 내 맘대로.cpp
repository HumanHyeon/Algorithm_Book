//https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x;

bool cmp(string a, string b)
{
    if (a[x] != b[x]) 
        return a[x] < b[x];
        
    else
        return a < b;
}

vector<string> solution(vector<string> strings, int n)
{
    x = n;

    sort(strings.begin(), strings.end(), cmp);

    return strings;
}
