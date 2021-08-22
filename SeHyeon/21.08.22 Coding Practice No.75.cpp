https://www.acmicpc.net/problem/18429

#include <iostream>
#include <algorithm>
#include <vector>
#define DEBUG 0
using namespace std;

int n, k;
vector<int> kitWeight;
int answer = 0;

bool isPossible(vector<int>& order) {
	static const int stdWeight = 500;
	int weight = 500;

	for (int i = 0; i < n; i++) {
		weight += kitWeight[order[i]];
		weight -= k;

		if (weight < stdWeight) {
			DEBUG && cout << "\n[false]\n" << endl;
			return (false);
		}
	}
	DEBUG && cout << "\n[true]\n" << endl;
	return (true);
}

bool isValid(vector<int>& order, int nowPos, int value) {
	for (int i = 0; i < nowPos; i++)
		if (order[i] == value)
			return (false);
	return (true);
}

void dfs(vector<int> order, int nowPos){
	if (nowPos == n) {
		for (int i = 0; i < n; i++)
			DEBUG && cout << order[i] << " ";
		DEBUG && cout << '\n';
		if (isPossible(order))
			answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isValid(order, nowPos, i)) {
			order[nowPos] = i;
			dfs(order, nowPos + 1);
		}
	}
}

int solution(int n, int k, vector<int> kitWeight) {
	vector<int> order(n);

	for (int i = 0; i < n; i++) {
		order[0] = i;
		dfs(order, 1);
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0, tmp; i < n; i++) {
		cin >> tmp;
		kitWeight.push_back(tmp);
	}
	cout << solution(n, k, kitWeight);
}
