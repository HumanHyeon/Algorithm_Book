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
    map<char, int> ::iterator iter;
    string input;
    string output;
    cin >> input;

    char compare = 'a';
    int count = 0;
    char lastword = *input.end();


    // 맵 구성하는 부분
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
    }

    // 모든 map의 키값을 순회하며 결과 삽입하는 법
    do
    {
        // output에 출력값을 삽입하는 부분
        // iter -> first or (*iter).first 는 맵의 키값에 접근
        // iter -> second or (*iter).second 는 맵의 벨류값에 접근
        for (iter = board.begin(); iter != board.end(); iter++)
        {
            output += iter->first;
            board[iter->first] -= 1;
            if(board[iter->first] == 0)
                board.erase(iter->first);            
        }
    } while (output.size() == input.size());
    
    // map의 키값을 앞에서 부터 차례대로 소모하며 삽입하는 법
    // for (int i = 0; i < input.size(); i++)
    // {
    //     output += iter->first;
    //     board[iter->first] -= 1;
    //     iter++;
    //     if (board[iter->first] == 0)
    //             board.erase(iter->first); 
    //     if (--iter->second != 0)
    //         iter--;
    // }

    cout << output;
}