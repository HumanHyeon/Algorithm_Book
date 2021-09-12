https://www.acmicpc.net/problem/22113

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> busList;
vector<vector<int>> busInfo;

int solution() {
	int answer = 0;
	int before = busList[0], after;

	for (int i = 1; i < m; i++) {
		after = busList[i];
		answer += busInfo[before][after];
		before = after;
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0, tmp; i < m; i++)
		cin >> tmp, busList.push_back(tmp - 1);
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0, tmp2; j < n; j++)
			cin >> tmp2, tmp.push_back(tmp2);
		busInfo.push_back(tmp);
	}
		
	cout << solution();
}
