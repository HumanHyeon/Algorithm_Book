#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int N, int M, vector<int> a, int size, int pos, int t, int &result) {
	if (t > M) return;
	
	result = max(size, result);

	if (pos + 1 <= N) solution(N, M, a, size + a[pos + 1], pos + 1, t + 1, result);
	if (pos + 2 <= N) solution(N, M, a, size / 2 + a[pos + 2], pos + 2, t + 1, result);
}

int main() {
	int N, M, result = 0;
	cin >> N >> M;

	vector<int> a(N + 1);

	a[0] = 0;

	for (int i = 1; i < N + 1; i++)
		cin >> a[i];

	solution(N, M, a, 1, 0, 0, result);

	cout << result;
}
