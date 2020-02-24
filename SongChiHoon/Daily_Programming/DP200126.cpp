// 주어진 string 에 모든 단어를 거꾸로 하시오.

// Reverse all the words in the given string.



// 예제)

// Input: “abc 123 apple”

// Output: “cba 321 elppa”
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string temp, temp2;
	string input = "abc 123 apple";
	string result = input;

	int start_point = 0;
	int count[3] = {0, 0, 0};

	cout << "Input : " << input << endl;

	for (int num = 0; num < 3; num++)
	{
		//result.find 에서 처음 나온 빈칸 까지의 길이 count에 저장
		count[num] = result.find(" ", start_point);

		if (num > 0)
			count[num] = count[num] - count[num - 1];

		//temp2에 첫 빈칸까지의 단어 저장
		temp2 = result.substr(start_point, count[num]);

		//temp에 단어의 역순으로 저장
		do
		{
			temp.push_back(temp2.back());
			temp2.pop_back();
		} while (temp2.empty() == false);

		//빈칸 찾기 시작점을 빈칸의 위치 다음칸으로 설정
		start_point = count[num] + 1;

		temp2.clear();
	}

	cout << "Output : " << temp;

	return 0;
}