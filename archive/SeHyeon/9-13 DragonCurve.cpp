#include <iostream>
#include <cassert>
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
using namespace std;

const int MAX = 1000000000 + 1;
int length[51];

const string EXPAND_X = "X+XF";
const string EXPAND_Y = "FX-Y";

void precalc() {
	length[0] = 1;
	for (int i = 0; i <= 50; i++)
		length[i] = MIN(MAX, length[i - 1] * 2 + 2);
}

char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); i++)
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations])	skip -= length[generations];
			else if (dragonCurve[i] == 'X')	return expand(EXPAND_X, generations - 1, skip);
			else return expand(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0)	--skip;
		else return dragonCurve[i];

	return '#';
}

int main() {
	string dragonCurve = "FX";
	int generations = 2;
	int skip = 4;

	precalc();
	cout << expand(dragonCurve, generations, skip) << endl;
}
