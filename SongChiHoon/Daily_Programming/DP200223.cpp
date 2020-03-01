// 길이가 같은 두 문자열(string) A 와 B가 주어지면, A 가 B 로 1:1 암호화 가능한지 찾으시오.

// Given two strings of equal length, check if two strings can be encrypted 1 to 1.

// 예제)

// Input: “EGG”, “FOO”

// Output: True // E->F, G->O



// Input: “ABBCD”, “APPLE”

// Output: True // A->A, B->P, C->L, D->E



// Input: “AAB”, “FOO”

// Output: False

#include <iostream>
using namespace std;

bool matching(string A, string B)
{
    int temp1, temp2, ret[26], count[26];

    for(int i = 0; i < A.length(); i++)
    {
        temp1 = A[i] - 65;      // ret 배열에서 알파뱃의 위치 정보
        temp2 = A[i] - B[i];    // 위치적 의미 함유

        if(ret[temp1] == 0)
        {
            ret[temp1] = temp2;
        }
        else if(ret[temp1] != temp2)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string Original;    string Comparison;

    cout << "Input : ";
    cin >> Original >> Comparison;

    int Length = Original.length();

    if(Length == Comparison.length())
    {
        if(matching(Original, Comparison) == true)
        {
            cout << "True";
        }
    }

    else
    {
        cout << "False";
    }

    return 0;
}