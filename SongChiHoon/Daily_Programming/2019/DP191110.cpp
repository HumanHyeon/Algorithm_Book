/*
string이 주어지면, 중복된 char가 없는 가장 긴 서브스트링 (substring)의 길이를 찾으시오.

Given a string, find the longest substring that does not have duplicate characters.

예제)
Input: “aabcbcbc”
Output: 3 // “abc”

Input: “aaaaaaaa”
Output: 1 // “a”

Input: “abbbcedd”
Output: 4 // “bced”

해쉬맵을 사용하여 char와 char의 인덱스를 저장하여 푼다.

string의 각 char를 보면서 해쉬맵에 있다면 substring 시작점을 char의 인덱스+1 로 두면 된다.

그리고 현재 char의 인덱스와 시작점의 거리를 계속 계산하여 가장 큰 값을 리턴하면 된다.
*/
#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

int main()
{
	int count = 0;
	string temp;

	string input1 = "aabcbcbc", input2 = "aaaaaaaaa", input3 = "abbbcedd";

	cout << "Input : \"" << input1 << "\"" << endl;

	for(int i = 0; i < SIZE; i ++)
	{
		if(input1[i] != temp[count])
		{
			temp.push_back(input1.at(i));
			count++;
		}
	}

	cout << "Output : \"" << count << "\"" << temp << "\"";
	return 0;
}
