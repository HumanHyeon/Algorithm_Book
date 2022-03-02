#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int M, vector<int> fee, vector<vector<int>> A) {
	int result = 0;

	for (int i = 1; i < fee.size(); i++) {
		int S = fee[i - 1];
		int E = fee[i];

		result += A[S - 1][E - 1];
	}

	cout << result;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> fee(M);
	vector<vector<int>> A(N, vector<int>(N));

	for (int i = 0; i < M; i++)
		cin >> fee[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];


	solve(N, M, fee, A);

	return 0;
}
