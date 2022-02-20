// https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int num[4];

int main() {
	cin >> N >> r >> c;

	int start = 0;
	while (1) {
		for (int i = 0; i < 4; i++)
			num[i] = i * pow(2, 2 * N - 2) + start;

		if (N == 1) break;

		int half = pow(2, N - 1);
		if (r < half && c < half)
			start = num[0];
		else if (r < half && c >= half) {
			start = num[1];
			c -= half;
		}
		else if (r >= half && c < half) {
			start = num[2];
			r -= half;
		}
		else if (r >= half && c >= half) {
			start = num[3];
			c -= half;
			r -= half;
		}
		N--;
	}

	cout << num[2 * r + c] << "\n";


	return 0;
}
