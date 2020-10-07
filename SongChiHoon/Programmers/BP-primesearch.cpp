#include <string>
#include <vector>
#include <cstdlib>
#include <set>

using namespace std;

void numbermaking(set<string> numberset, string numbers, int digit, string temp = "") {
	digit = digit - 1;
	if (digit >= 0) {
		for (int i = 0; i < numbers.size(); i++) {
			temp += numbers[i];
			numberset.insert(temp);
			numbermaking(numberset, numbers, digit, temp);
		}
	}
}

int numcount(set<string> numberset) {
	int primecounter = 0;
	set<string>::iterator it;
	int target;
	for (it = numberset.begin(); it != numberset.end(); it++) {
		target = stoi(*it);
		for (int i = 2; i < target; i++) {
			if(target % i != 0) {
				primecounter++;
			}
		}
	}
	return primecounter;
}

int solution(string numbers) {
	set<string> numberset;
    int answer = 0;
	string temp;
	numbermaking(numberset, numbers, numbers.size(), temp);
	answer = numcount(numberset);
    return answer;
}