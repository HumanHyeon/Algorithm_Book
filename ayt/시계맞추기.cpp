#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
bool areAligned(const vector<int>& clocks) {
	int s = 0;
	for (int i = 0; i < 16; i++) {
		if (clocks[i] == 12)
			++s;
	}
	if (s == 16) return true;
	else false;
}
void push(vector<int>& clocks, int swtch) {
	for(int clock = 0; clock < CLOCKS; ++clock)
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
}
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1)); //이부분 모르겠음
		push(clocks, swtch);
	}
	return ret;
}

int main(void) {
	int C;
	vector<int> clocks;
	int result;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 16; j++) {
			if (rand() % 4 == 0) {
				cout << "12";
				clocks[j] = 12;
			}
			else if (rand() % 4 == 1) {
				cout << "3";
				clocks[j] = 3;
			}
			else if (rand() % 4 == 2) {
				cout << "6";
				clocks[j] = 6;
			}
			else {
				cout << "9";
				clocks[j] = 9;
			}
		}
		cout << endl;
	}
	cout << endl;
	result = solve(clocks, 0);
	for (int i = 0; i < C; i++)
		cout << result << endl;
}
