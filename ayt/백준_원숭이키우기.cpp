#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int> ch, vector<int> lv, int day) {
	vector<int> dif(ch.size() - 1);

	for (int i = 1; i < ch.size(); i++)
		dif[i - 1] = lv[i] - lv[i - 1];

	for (int i = 0; i < day; i++) {
		int max = 0;
		int maxId = 0;
		for (int j = 0; j < dif.size(); j++) {
			if (max < dif[j] && ch[j] >= 0) {
				max = dif[j];
				maxId = j;
			}
		}
		ch[maxId + 1]++;
		ch[maxId]--;
	}

	int res = 0;
	for (int i = 0; i < ch.size(); i++)
		res += (ch[i] * lv[i]);

	cout << res;
}

int main() {
	int N;
	cin >> N;

	vector<int> ch(N);
	vector<int> lv(N);

	for (int i = 0; i < N; i++)
		cin >> ch[i];
	for (int i = 0; i < N; i++)
		cin >> lv[i];

	int day;
	cin >> day;

	solution(ch, lv, day);

	return 0;
}
