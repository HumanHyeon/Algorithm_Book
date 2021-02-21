#include <iostream>
using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

int lis(int start) {
	int& ret = cacheLen[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next)
		if (start == -1 || S[start] < S[next])
			ret = max(ret, lis(next) + 1);
	return ret;
}

int count(int start) {
	if (lis(start) == 1)	return 1;
	int& ret = cacheCnt[start + 1];
	if (ret != -1)	return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == list(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}
