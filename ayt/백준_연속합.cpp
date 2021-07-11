#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> array) {
	vector<int> dp = array;
	int sum = dp[0];

	for (int i = 1; i < n; i++) {
		if (sum + array[i] >= array[i]) {
			sum += array[i];
			dp[i] = sum;
		}
		else {
			sum = dp[i];
		}
	}

	int max = -1001;

	for (auto elem : dp)
		if (elem > max) max = elem;

	return max;
}

int main() {
	int n;
	cin >> n;

	vector<int> array(n);

	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	cout << solution(n, array) << endl;
}
