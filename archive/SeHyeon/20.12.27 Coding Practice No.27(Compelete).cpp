#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land){
	for (int i = 1; i < land.size(); i++) {
		int beforeMax = *max_element(land[i - 1].begin(), land[i - 1].end());
		int beforeIndex = find(land[i - 1].begin(), land[i - 1].end(), beforeMax) - land[i - 1].begin();
		for (int j = 0; j < 4; j++) 
			if (j != beforeIndex)	land[i][j] += beforeMax;
			else {
				land[i - 1][beforeIndex] = -1;
				land[i][j] += *max_element(land[i - 1].begin(), land[i - 1].end());
			}
	}
	return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}
