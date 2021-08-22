#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int K, vector<int> ex) {
	int result = 0;
	vector<int> id(ex.size());

	for (int i = 0; i < ex.size(); i++)
		id[i] = i;

	do {
		int sum = 0;
		bool ck = true;
		for (auto elem : id) {
			sum += (ex[elem] - K);
			if (sum < 0) {
				ck = false;
				break;
			}
		}
		if(ck) result++;
	} while (next_permutation(id.begin(), id.end()));

	cout << result;
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> ex(N);

	for (int i = 0; i < N; i++)
		cin >> ex[i];

	solution(K, ex);

	return 0;
}
