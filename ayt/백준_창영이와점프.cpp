#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int K, vector<int> dis) {
	int result = -1;

	for (int i = 0; i < dis.size();i++) {
		int cur = 1;
		bool jump = true;

		for (int j = i; j < dis.size(); j++) {
			if (dis[j] <= K)
				++cur;
			else {
				if (jump) {
					jump = false;
					++cur;
				}
				else
					break;
			}
		}
		result = (cur > result) ? cur : result;
	}

	cout << result;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> dis(N-1);

	for (int i = 0; i < N - 1; i++)
		cin >> dis[i];

	solve(N, K, dis);

	return 0;
}
