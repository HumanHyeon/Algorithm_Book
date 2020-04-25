// 정수 n이 주어지면, n개의 여는 괄호 "("와 n개의 닫는 괄호 ")"로 만들 수 있는 괄호 조합을 모두 구하시오. (시간 복잡도 제한 없습니다).

// Given an integer N, find the number of possible balanced parentheses with N opening and closing brackets.

// 예제)

// Input: 1

// Output: ["()"]

// Input: 2

// Output: ["(())", "()()"]

// Input: 3

// Output: ["((()))", "(()())", "()(())", "(())()", "()()()"]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class parentheses
{
private:
    int amount;
    string start = "(";
    string end = ")";
public:
    parentheses(int number);
    ~parentheses();
};

parentheses::parentheses(int number)
{
    amount = number;
}

parentheses::~parentheses()
{
}



int main()
{   
    int input;
    cout << "Input : ";
    cin >> input;

    return 0;
}