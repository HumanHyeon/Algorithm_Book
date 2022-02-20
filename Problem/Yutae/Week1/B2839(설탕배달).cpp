// https://www.acmicpc.net/problem/2839

#include <iostream>

using namespace std;

int N;

void solution() {
	int res = 0;

	while (N>=0) {
		if (N % 5 == 0) {
			res += (N / 5);
			cout << res << "\n";
			return;
		}
		N -= 3;
		res++;
	}

	cout << "-1\n";
}

int main() {
	cin >> N;

	solution();

	return 0;
}
