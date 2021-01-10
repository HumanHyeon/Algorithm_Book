#include <string>
#include <vector>
using namespace std;

int answer[2];

void calc(vector<vector<int>>& arr, int startx, int starty, int endx, int endy) {
	bool unionCheck = true;
	int checkNum = arr[starty][startx];

	for (int i = starty; i < endy; i++) {
		bool flag = false;
		for (int j = startx; j < endx; j++) {
			if (checkNum != arr[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			unionCheck = false;
			break;
		}
	}

	if (unionCheck) {
		answer[checkNum]++;
		return;
	}
	else {
		calc(arr, startx, starty, startx + (endx - startx) / 2, starty + (endy - starty) / 2);
		calc(arr, startx + (endx - startx) / 2, starty, endx, starty + (endy - starty) / 2);
		calc(arr, startx, starty + (endy - starty) / 2, startx + (endx - startx) / 2, endy);
		calc(arr, startx + (endx - startx) / 2, starty + (endy - starty) / 2, endx, endy);
	}
}

vector<int> solution(vector<vector<int>> arr) {
	calc(arr, 0, 0, arr.size(), arr[0].size());
	return { answer[0], answer[1] };
}
