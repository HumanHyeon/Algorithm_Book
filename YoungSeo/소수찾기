#include<string>
#include<vector>
#include<cmath>
 
using namespace std;
 
bool Visit[10000000];
bool Select[10];
int Answer;
 
bool IsPrime(int N)
{
    if (N == 0 || N == 1) return false;
 
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0) return false;
    }
    return true;
}
 
void DFS(int Cnt, string S, string Res)
{
    if(Res != "" && Visit[stoi(Res)] == false)
    {
        int Num = stoi(Res);
        Visit[Num] = true;
        if (IsPrime(Num) == true) Answer++;
    }
 
    for (int i = 0; i < S.length(); i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(Cnt + 1, S, Res + S[i]);
        Select[i] = false;
    }
}
 
int solution(string S)
{
    DFS(0, S, "");
    return Answer;
}
