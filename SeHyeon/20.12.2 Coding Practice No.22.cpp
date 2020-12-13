#include <string>
#define PNT(N) ((N) == 1 || (N) == 2 ? (N) : 4)
using namespace std;

string solution(int n) {
	string answer = "";
	int div = n, mod;
	while(div != 0) {
		mod = div % 3;
		div = div / 3;
		if (!mod)	div--;
		answer = to_string(PNT(mod)) + answer;
	}
    return answer;
}
