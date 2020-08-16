#include <iostream>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

const int M = 1000000000 + 100;
int bino[201][201];
int skip;

void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = MIN(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

string kth(int n, int m, int skip) {
	if (n == 0)	return string(m, 'o');
	if (skip < bino[n + m - 1][n - 1])	return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main() {
	int k;		cin >> k;		skip = k;
	int n, m;	cin >> n >> m;

	calcBino();
	cout << kth(n, m, skip) << endl;
}
