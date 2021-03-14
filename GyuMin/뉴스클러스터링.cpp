//https://programmers.co.kr/learn/courses/30/lessons/17677
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;

    string TWO = "";

    vector <string> str1_v;
    vector <string> str2_v;

    double n = 0;
    double u;

    for (char a : str1)
        if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')))
        {
            TWO.push_back(tolower(a));

            if (TWO.size() == 2)
            {
                str1_v.push_back(TWO);

                TWO.erase(0, 1);
            }
        }

        else
            TWO.clear();

    TWO.clear();

    for (char a : str2)
        if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')))
        {
            TWO.push_back(tolower(a));

            if (TWO.size() == 2)
            {
                str2_v.push_back(TWO);

                TWO.erase(0, 1);
            }
        }

        else
            TWO.clear();

    for (int i = 0; i < str1_v.size(); i++)
        for (int j = 0; j < str2_v.size(); j++)
            if (str1_v[i] == str2_v[j])
            {
                str1_v.erase(str1_v.begin() + i);
                str2_v.erase(str2_v.begin() + j);
                i--;
                j--;
                n++;
            }

    u = str1_v.size() + str2_v.size() + n;

    if (u == 0)
        answer = 65536;

    else
        answer = n / u * 65536;

    return answer;
}
