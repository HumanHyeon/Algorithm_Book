#include <iostream>
#define FOR(a) for(int z = (a); z < sizeof(input) / sizeof(input[0]); z++) 
#define LIMIT input[standardstr].size()
#pragma warning(disable:4018)
using namespace std;

//string input[] = { "apple", "apps", "ape" };
//string input[] = { "hawail", "happy" };
string input[] = { "dog", "dogs", "doge" };

string prefix(int standardstr) {
	string returnstr, comparestr;
	returnstr = comparestr = "";

	bool identify = true;
	for (int i = 0; i <= LIMIT; i++) 
		for (int j = 0; j <= LIMIT; j++) {
			for (int k = i; k < LIMIT - j; k++) 
				comparestr += input[standardstr][k];
			FOR(0) {
				if (z == standardstr)	continue;
				if ((signed)input[z].find(comparestr) == -1)	identify = false;
			}
			if (identify)
				if (returnstr.size() < comparestr.size())
					returnstr = comparestr;
			comparestr = "", identify = true;
		}
	return returnstr;
}

int main() {
	int shortindex = 0;
	FOR(1)	if (input[shortindex].size() > input[z].size())	shortindex = z;
	cout << prefix(shortindex) << endl;
}
