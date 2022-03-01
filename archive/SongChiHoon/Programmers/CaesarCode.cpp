#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string input;

    cin >> input;

    int n;
    
    cin >> n;

    string answer = "";

    char letter, start;
    int movesize;
    
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] != ' ')
        {
            start = ('A' <= input[i] && input[i] <= 'Z')? 'A' : 'a';
            letter = start + (input[i] + n - start)%26;
        }
        else
            letter = ' ';
        answer.push_back(letter);
    }
}