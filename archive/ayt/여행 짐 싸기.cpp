#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, capacity;                  //캐리어에 남은 용량이 capacity일 때, item 이후의 물건들을
int volume[100], need[100];       //담아 얻을 수 있는 최대 절박도의 합을 반환
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
	if (item == n) return 0;             //기저 사례: 더 담을 물건이 없을 때
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;            //이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	if (capacity >= volume[item])        //이 물건을 담을 경우
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);

	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n)return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	int C;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		cin >> n >> capacity;
		vector<string> picked;
		for (int j = 0; j < n; ++j) {
			cin >> name[j] >> volume[j] >> need[j];
			for (int k = 0; k < 1001; ++k) 
				cache[k][j] = -1;
		}
		reconstruct(capacity, 0, picked);
		cout << pack(capacity, 0) << " " << picked.size() << endl;
		for (int j = 0; j < picked.size(); ++j)
			cout << picked[j] << endl;
	}

	return 0;
}
