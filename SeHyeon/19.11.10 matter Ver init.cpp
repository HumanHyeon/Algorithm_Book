//한 문자로 지속되는 문자열 구별x
//서로 다른 문자여도 앞에서 기록한 문자열인 경우 개수를 셈 ex) abcabc 정답 : 3 (코드 : 6)
//끊어졌다가 시작하는경우도 계속 개수를 셈

#include <iostream>
#include <string>
using namespace std;

int subString(string input, int max, char prechar = NULL) 
{
	int output = 0;

	if(input.length() == 0)
		return 0;	

	if (input.length() == max) {
		return output += subString(input.substr(1), max, input[0]);
	}
	else {
		if (prechar == input[0])	return 0 + subString(input.substr(1), max, input[0]);
		else return 1 + subString(input.substr(1), max, input[0]);

	}
}

int main()
{
	string input;
	cin >> input;
	
	int result = subString(input, input.length());
	cout << result << endl;
}
