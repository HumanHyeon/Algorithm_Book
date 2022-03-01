#include <iostream>
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

int main() {
	int testcase;	cin >> testcase;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < testcase; i++) {
		cin >> n >> capacity;

		for (int j = 0; j < n; j++) 
			cin >> name[j] >> volume[j] >> need[j];
		
		pack(capacity, 0);

		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 100; j++)
				cout << cache[i][j] << " ";
			putchar('\n');
		}
	}
}
