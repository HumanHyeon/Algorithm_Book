//https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    string a;

    int A;
    int B;

    int pow_2;

    for (int x = 0; x < n; x++)
    {
        A = arr1[x];
        B = arr2[x];

        for (int i = n - 1; i >= 0; i--)
        {
            pow_2 = pow(2, i);

            if ((pow_2 > A) && (pow_2 > B))
                a.push_back(' ');

            else
                a.push_back('#');

            if (pow_2 <= A)
                A -= pow_2;

            if (pow_2 <= B)
                B -= pow_2;        
        }
        answer.push_back(a);

        a.clear();
    }

    return answer;
}
