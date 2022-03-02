#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string main()
{
    int n;
    string answer = "";
    cin >> n;

    int size = n / 2;
    
    for(int i = 0 ; i < size; i++)
    {
        answer += "수박";
    }
    if(n%2 != 0)
        answer += "수";

    return answer;
}
