//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
using namespace std;
string solution(int n)
{
	string answer = "";
	for (;;)
	{
		switch (n % 3)
		{
		case 0:
			answer = "4" + answer;
			break;
		case 1:
			answer = "1" + answer;
			break;
		case 2:
			answer = "2" + answer;
			break;
		}
		if (n <= 3)
			break;
		else if (!(n % 3))
			n = (n - 1) / 3;
		else
			n = n / 3;
	}
    return answer;
}
