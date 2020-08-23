#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

void reconstruct(int start, int skip, vector<int>& lis) {
	if (start != -1)	lis.push_back(S[start]);
	vector<pair<int, int>> followers;
	for (int next = start + 1; next < n; ++next)
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());

	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)	skip -= cnt;
		else {
			reconstruct(idx, skip, lis);
			break;
		}
	}
}
