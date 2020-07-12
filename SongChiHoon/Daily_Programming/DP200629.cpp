// 반복된 알파벳으로 이루어진 문자배열이 주어지면 연속으로 중복된 알파벳이 없도록 문자배열을 재배열하여 리턴하시오. 불가능 하다면 empty string을 리턴하시오.



// Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is impossible, return an empty string.



// input: "aaabbc"

// output: "ababac"



// input: "aaac"

// output: ""

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<char, int> board;
    string input;
    string output;
    cin >> input;

    char compare = 'a';
    int count = 0;
    char lastword = *input.end();

    for (int i = 0; i < input.size(); i++)
    {
        if(compare == input[i])
        {
            count++;
        }
        else
        {
            board.insert(pair<char, int>(compare, count));
            count = 1;
            compare++;
        }
        output.push_back(board['a']);
    }
    
}