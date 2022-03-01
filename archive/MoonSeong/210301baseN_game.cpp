#include <string>
#include <vector>

using namespace std;

string decToN(int num, int n) {    
    int q = num / n;
    int r = num % n;
    string strNum = "0123456789ABCDEF";
    
    if (q == 0)
        return strNum.substr(r, 1);
    else
        return decToN(q, n) + strNum.substr(r, 1);
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string gameStr = "";
    
    int i = 0;
    while (gameStr.length() < m * (t-1) + p)
        gameStr += decToN(i++, n);
    
    for (int i = 0; i < t; i++)
        answer += gameStr[i * m + (p-1)];
    
    return answer;
}
