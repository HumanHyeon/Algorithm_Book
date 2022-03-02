https://www.acmicpc.net/problem/22114

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> block;

int countStep(int sp) {
	bool jump = true;
	int count = 1;

	for (int i = sp; i < n; i++) {
		if (block[i] > k) {
			if (!jump)
				break;
			jump = false;
		}
		count++;
	}

	return (count);
}

int solution() {
	int answer = 0;

	for (int startPoint = 0; startPoint < n; startPoint++)
		answer = max(answer, countStep(startPoint));
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	n--;
	for (int i = 0, tmp; i < n; i++)
		cin >> tmp, block.push_back(tmp);
	cout << solution();
}
