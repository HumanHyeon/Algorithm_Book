// input : aaaaabbbbbcccccdddddd

#include <iostream>
#include <string>
using namespace std;

int main() {

    string input, answer;
    char pointer;

    cin >> input;

    answer.push_back(input[0]);
    
    for (int i = 0; i < input.size(); i++)
    {
        pointer = input[i];
        pointer != *answer.end() ? answer.push_back(pointer) : pointer = input[i];
    }
    

    return 0;
}