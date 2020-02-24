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

해결방법 1 : C++ STL의 해쉬맵(Hashmap)을 활용하는 방법
해결방법 2 : Set 활용하는 방법
)
*/
#include <iostream>
#include <string>
using namespace std;

char ret[10];
int startlen = 1;
int retlen = 1;

void overlapsearch(const string input, string temp, unsigned int *count)
{
	int p = *count;
	temp = input.substr(p, startlen);

	count++;

	if (temp.find(input.substr(p, startlen)) != false)
	{
		temp.pop_back();
		overlapsearch(input, temp, count);
	}
	else
	{
		retlen++;
		overlapsearch(input, temp, count);
	}

    temp.copy(ret, retlen, startlen);

	// for(int i = 0; i < sizeof(input)/sizeof(char); i++)
	// {
	//     char temp = input.at(i);
	//     tempo.push_back(temp);
	//     if(temp == tempo.back)  tempo.pop_back();
	//     else    count++;
	// }

	cout << "\nOutput : ", cout << count, cout << " // ", cout << ret;
}

int main()
{
	string temp;
	unsigned int count = 0;

	string input1 = "aabcbcbc", input2 = "aaaaaaaaa", input3 = "abbbcedd";

	cout << "Input : \"" << input1 << "\"" << endl;

	overlapsearch(input1, temp, &count);

	return 0;
}