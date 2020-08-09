#include <iostream>
#include <vector>
using namespace std;

int n, capacity;
int volume[100], need[100];
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
	if (item == n)	return 0;

	int& ret = cache[capacity][item];
	
	if (ret != -1)	return ret;		//already pack
	ret = pack(capacity, item + 1);

	if (capacity >= volume[item]) {
		int tmp = pack(capacity - volume[item], item + 1) + need[item];
		ret = (ret > tmp ? ret : tmp);
	}
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n)	return;
	if (pack(capacity, item) == pack(capacity, item + 1))	//need not to pick
		reconstruct(capacity, item + 1, picked);
	else {													//need pick
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	vector<string> picked;
	int testcase;	cin >> testcase;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < testcase; i++) {
		cin >> n >> capacity;

		for (int j = 0; j < n; j++) 
			cin >> name[j] >> volume[j] >> need[j];
		
		reconstruct(capacity, 0, picked);
	}

	for (int i = 0; i < picked.size(); i++)
		cout << picked[i] << endl;
}
