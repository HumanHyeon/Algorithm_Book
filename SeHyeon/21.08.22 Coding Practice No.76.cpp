#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define DEBUG 0
using namespace std;

int n;
vector<int> level;
vector<int> power;
int d;

queue<int> desPower() {
	queue<int> order;
	vector<int> tmpPower = power;

	for (int i = 0, input; i < n; i++) {
		input = max_element(tmpPower.begin(), tmpPower.end()) - tmpPower.begin();
		order.push(input);
		tmpPower[input] = -1;
	}
	return (order);
}

int sumPower() {
	int sum = 0;

	for (int i = 0; i < n; i++) 
		sum += (level[i] * power[i]);
	return (sum);
}

int nextLevelUP(queue<int> order) {
	int nextLevel, index;

	nextLevel = -1;
	while (!order.empty()) {
		index = order.front();
		if (index != 0) {
			if (level[index - 1] != 0) {
				nextLevel = index - 1;
				break;
			}
		}
		order.pop();
	}
	return (nextLevel);
}

int solution() {
	int answer;
	queue<int> order;

	order = desPower();
	answer = sumPower();
	DEBUG&& cout << "\n------------- DEBUG MODE --------------\n";
	for (int i = 0, index, tmp; i < d; i++) {
		DEBUG && cout << "sol " << i << " for syntax doing\n\tanswer = " << answer << "\n";
		index = nextLevelUP(order);
		DEBUG && cout << "\tindex = " << index << "\n";
		level[index]--;
		level[index + 1]++;
		tmp = sumPower();
		DEBUG && cout << "\ttmp = " << tmp << "\n";
		if (answer >= tmp)
			break;
		answer = tmp;
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> n;
	level.resize(n);
	for (int i = 0; i < level.size(); i++)
		cin >> level[i];
	power.resize(n);
	for (int i = 0; i < power.size(); i++)
		cin >> power[i];
	cin >> d;
	cout << solution();
}
