#include <string>
#include <vector>
#include <cstdlib>
#include <hash_set>

using namespace std;

int numcount(hash_set<char> numberset, int digit) {
	int ret;
	string temp;
	if (digit == 0)
	{
		return numberset
	}

	for (int i = 0; i < digit; i++)
	{
		temp += numberset;
	}

	return ret;
}

int solution(string numbers) {
	hash_set<char> numberset;
    int answer = 0;

    for (int i = 0; i < numbers.size(); i++) {
    	numberset.insert(numbers[i]);
    }

    string temp;
    for (int i = 0; i < numbers.size(); i++)
    {
    	answer += numcount(numberset, i + 1);
    }
    return answer;
}