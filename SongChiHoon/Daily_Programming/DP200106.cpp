// 정수(int)가 주어지면, 팰린드롬(palindrome)인지 알아내시오. 팰린드롬이란, 앞에서부터 읽으나 뒤에서부터 읽으나 같은 단어를 말합니다. 단, 정수를 문자열로 바꾸면 안됩니다.

// Given an integer, check if it is a palindrome.

// 예제)

// Input: 12345

// Output: False


// Input: -101

// Output: False


// Input: 11111

// Output: True


// Input: 12421

// Output: True
#include <iostream>
using namespace std;

int main()
{
	int input;

	cout << "Input : ";
	cin >> input;
	
	int temp1 = 0;
	int temp2 = input;

	do
	{
		int count = temp2 % 10;
		temp2 = temp2 / 10;
		temp1 = (temp1 + count) * 10;
	} while (temp2 > 0);

	temp1 /= 10;

	if (temp1 == input)
	{
        cout << "Output : " << temp1 << ".\nTrue";
	}
	else
	{
		cout << "Output : " << temp1 << ".\nFalse";
	}
	return 0;
}