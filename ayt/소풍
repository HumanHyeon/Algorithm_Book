#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];
int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
int main() {
	int C, a, b, m;
	bool take[10];
	cout << "테스트 케이스 : ";
	cin >> C;
	for (int i = 0; i < C; i++) {
		cout << "학생 수, 친구 쌍의 수 : ";
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			cout << j + 1 << "번째 짝1, 짝2 : ";
			cin >> a >> b;
			areFriends[a][b] = true;
			take[a] = true;
			take[b] = true;
		}
		countPairings(take);
	}
}
